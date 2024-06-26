#include "Server.hpp"
#include "ACommand.hpp"
#include "Bot.hpp"
#include "User.hpp"

#include <cstddef>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

Server::Server() {

}

Server::Server(int port, std::string const & password) {
	this->_port = port; //verifier le port
	if (!createSocketServer())
	{
	std::cerr << "ERROR: socket creation failed" << std::endl;
		throw std::exception();
	}
	for (int i = 0 ; i < MAX_CONNECTIONS ; i++)
		this->_all_connections[i] = -1;
	this->_nb_connections = 1;
	this->_all_connections[0] = this->_socket;
	this->_password = password;
}

Server::Server( const Server& obj ) {

	*this = obj;
}

Server& Server::operator=( const Server& obj ) {

	if (this == &obj )
		return *this;
    for (int i = 0; i < MAX_CONNECTIONS; ++i) {
        this->_all_connections[i] = obj._all_connections[i];
    }
    this->_socket = obj._socket;
    this->_users = obj._users;
    this->_fd_to_read = obj._fd_to_read;
    this->_password = obj._password;
    this->_nb_connections = obj._nb_connections;
    this->_port = obj._port;
    this->_command = obj._command;
    this->_channels = obj._channels;

	return *this;
}

Server::~Server() {

}

int Server::createSocketServer()
{
	struct sockaddr_in addr;

	this->_socket = socket(AF_INET, SOCK_STREAM, 0); // ici on recupère le FD du socket
	if (this->_socket == -1)
		return (0); //erreur socket
	int opt = 1; // Verifier pourquoi 1
	setsockopt(this->_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	addr.sin_family = AF_INET; // IPV4
	addr.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
	addr.sin_port = htons(this->_port); // Port
	if (bind(this->_socket, (struct sockaddr *)&addr, sizeof(addr)) != 0)
		return (0);
	if (listen(this->_socket, MAX_CONNECTIONS))
		return (0);
	return (1);
}

int	Server::addNewConnections()
{
	int new_fd;
	struct sockaddr_in new_addr;
	unsigned int addrlen = sizeof(new_addr);

	if (FD_ISSET(this->_socket, &this->_fd_to_read))
	{
		/* accept the new connection */
		new_fd = accept(this->_socket, (struct sockaddr*)&new_addr, &addrlen);
		if (new_fd >= 0 && this->_nb_connections != MAX_CONNECTIONS) {
			std::cout << "Accepted a new connection with fd: " << new_fd << std::endl;
			for (int i = 0 ; i < MAX_CONNECTIONS ; i++) {
				if (this->_all_connections[i] < 0) {
					// fd du User qu on vient d'accepter
					this->_all_connections[i] = new_fd;
					User* user = new User(new_fd);
					this->_users.push_back(user);
					sendMessage(new_fd, "Welcome to our awesome IRC server\nTo login please use commands: PASS (if required) | NICK (12 chars. max) | USER (12 chars. max) in this order.\r\n");
					this->_nb_connections++;
					break;
				}
			}
		}
		else
		{
			sendMessageError(new_fd, "ERROR", "too many clients");
			return (0);
		}
	}
	return (1);
}

int	Server::recvMessage()
{
	std::vector<char> buffer(MAX_BUF_LENGTH);
	User* user;
	std::string rcv_msg;
	int recv_val = 1;

	for (int i = 1 ; i < MAX_CONNECTIONS; i++) {
		if ((this->_all_connections[i] > 0) && (FD_ISSET(this->_all_connections[i], &this->_fd_to_read))) {
			recv_val = recv(this->_all_connections[i], &buffer[0] , buffer.size(), 0);
			user = getUserByFd(this->_all_connections[i]);
			if (recv_val > 0)
			{
				for (int i = 0; i < recv_val; i++)
					rcv_msg.push_back(buffer[i]);
				user->appendBufferMsg(rcv_msg);
				rcv_msg.clear();
			}
			else if (recv_val == 0)
			{
				std::cout << "Client " << this->_all_connections[i] << " disconnected" << std::endl;
				deleteUser(this->_all_connections[i]);
				continue;
			}
			else
			{
				std::cerr << "ERROR" << std::endl;
			}
			if (user->getBufferMsg().size() > 0 && (user->getBufferMsg()[user->getBufferMsg().size() - 2] == '\r' || user->getBufferMsg()[user->getBufferMsg().size() - 1] == '\n'))
			{
				dispatch(user->getBufferMsg(), this->_all_connections[i]);
				if (this->_all_connections[i] > 0)
					user->getBufferMsg().clear();
			}
		}
	}
	return (1);
}

int	Server::sendMessage( int cli_fd, std::string const & message )
{
	send(cli_fd, message.c_str(), message.size(), 0);
	return (1);
}

int Server::sendMessageBetweenUsers(int start_fd, std::string target, std::string const & message)
{
	std::string msg = ":" + getUserByFd(start_fd)->getNickname() + " " + "PRIVMSG " + target + " :" + message + "\r\n";
	sendMessage(getUserByNickname(target)->getFd(), msg);
	return (1);
}

int	Server::sendMessageError( int cli_fd, std::string num_error, std::string const & message )
{
	std::string num_error_msg;
	std::string error_msg;

	num_error_msg = ": " + num_error + " " + getUserByFd(cli_fd)->getNickname() + "\r\n";
	error_msg = "ERROR :" + message + ". Please retry.\r\n";
	send(cli_fd, num_error_msg.c_str(), num_error_msg.size(), 0);
	send(cli_fd, error_msg.c_str(), error_msg.size(), 0);
	return (1);
}

int	Server::sendMessageChannel(Channel *channel, std::string const & message )
{
	std::map<User*, int> users = channel->getUsers();
	for (std::map<User*, int>::iterator it = users.begin(); it != users.end(); ++it)
	{
		sendMessage((*it).first->getFd(), message);
	}
	return (1);
}

void Server::loginError( int cli_fd, std::string num_error, std::string message)
{
	sendMessageError(cli_fd, num_error, message);
	getUserByFd(cli_fd)->setToDisconnect();
}

int	Server::isValidUsername(std::string const & str)
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalnum(str[i]))
			return (0);
	}
	return (1);
}

int	Server::isValidPass(std::string const & str)
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isprint(str[i]))
			return (0);
	}
	return (1);
}

std::vector<std::string> Server::split(std::string const & str, char separator)
{
	std::vector<std::string> split_msg;
	std::string tmp;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == separator)
		{
			split_msg.push_back(tmp);
			tmp.clear();
		}
		else
			tmp.push_back(str[i]);
	}
	if (tmp.size() > 0)
		split_msg.push_back(tmp);
	return (split_msg);
}

void Server::dispatch( std::string const recv_msg, int cli_fd )
{
	std::string arg;
	ACommand* command;
	User *user = this->getUserByFd(cli_fd);
	std::vector<std::string> parameters;

	if (user == NULL || recv_msg == "CAP LS 302\r\n")
		return ;
	std::cout << "recv_msg : " << recv_msg << std::endl;
	for (size_t i = 0; i < recv_msg.size(); i++)
	{
		if ((recv_msg[i] == '\r' && (recv_msg.size() > (i + 1) && recv_msg[i + 1] == '\n')) || recv_msg[i] == '\n')
		{
			char tmp = recv_msg[i];
			if (arg != "CAP LS 302" && !arg.empty())
			{
				parameters = split(arg, ' ');

				command = this->getCommand(parameters[0]);
				if (command == NULL)
				{
					this->sendMessageError(cli_fd, "421", "invalid command");
					break ;
				}
				parameters.erase(parameters.begin());
				if (parameters.size() >= 2 && parameters[1][0] == ':')
					parameters[1].erase(0, 1);
				if (command->loginRequired() && user && !user->isLog())
					this->sendMessageError(cli_fd, "451", "You have not registered");
				else
				{
					command->execute(parameters, user, this);
					if (user->getToDisconnect())
					{
						deleteUser(cli_fd);
						break ;
					}
				}
			}
			if (tmp == '\r')
				i++;
			arg.clear();
		}
		else
			arg.push_back(recv_msg[i]);
	}
}

ACommand* Server::getCommand( std::string const & name ) const {

	if (_command.find(name) != _command.end())
		return (_command.find(name)->second);
	std::cout << "NULL" << std::endl;
	return (NULL);
}

void Server::addCommand(ACommand* command ) {

	_command[command->getName()] = command;
}

void Server::run()
{
	std::cout << "Server start" << std::endl;

	addCommand(new Pass());
	addCommand(new Nick());
	addCommand(new UserName());
	addCommand(new Join());
	addCommand(new Topic());
	addCommand(new Message());
	addCommand(new Mode());
	addCommand(new Invite());
	addCommand(new Kick());
	addCommand(new Who());
	addCommand(new Part());
	addCommand(new Quit());

	while (1)
	{
		FD_ZERO(&this->_fd_to_read);
		for (int i = 0 ; i < MAX_CONNECTIONS; i++) {
			if (this->_all_connections[i] >= 0) {
				FD_SET(this->_all_connections[i], &this->_fd_to_read);
			}
		}
		int nb_cli = select(FD_SETSIZE, &this->_fd_to_read, NULL, NULL, NULL);
		if (nb_cli >= 0)
		{
			addNewConnections();
        }
        if (nb_cli != 0)
		{
			recvMessage();
        }
    }
}

void Server::addUser( User* user ) {

	this->_users.push_back(user);
}

void Server::addChannel( Channel* channel ) {

	this->_channels[channel->getName()] = channel;
}

User* Server::getUserByNickname( std::string const & nickname ) const {

	for ( size_t i = 0 ; i < this->_users.size() ; i++ )
	{
		if ( this->_users[i]->getNickname() == nickname )
			return this->_users[i];
	}
	return NULL;
}

User* Server::getUserByFd( int fd ) const {

	for ( size_t i = 0 ; i < this->_users.size() ; i++ )
	{
		if ( this->_users[i]->getFd() == fd )
			return this->_users[i];
	}
	return NULL;
}

std::vector<User*> Server::getUserList() const {

	return this->_users;
}

Channel* Server::getChannelByName( std::string const & channel ) const {

	if (this->_channels.find(channel) != this->_channels.end())
		return this->_channels.find(channel)->second;
	return NULL;
}

std::string const & Server::getPassword() const {

	return this->_password;
}

void Server::deleteUser(int cli_fd) {

	User* user = this->getUserByFd(cli_fd);
    std::map<std::string, Channel*>::iterator it = this->_channels.begin();
    std::map<std::string, Channel*>::iterator end = this->_channels.end();
	while (it != end)
	{
		if (it->second->getUsers().find(user) != it->second->getUsers().end())
		{
			it->second->getUsers().erase(user);
			sendMessageChannel(it->second, ":" + user->getNickname() + " QUIT\r\n");
		}
		if (it->second->getUsers().size() == 0)
		{
			deleteChannel(it->first);
			it = this->_channels.begin();
			end = this->_channels.end();
		}
		else
		{
			it++;
		}
	}
    for (size_t i = 0; i < this->_users.size(); i++)
    {
        if (&this->_users[i]->getNickname() == &user->getNickname())
        {
			delete this->_users[i];
            this->_users.erase(this->_users.begin() + i);
        }
    }
	close(cli_fd);
	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if (this->_all_connections[i] == cli_fd)
		{
			this->_all_connections[i] = -1;
			this->_nb_connections--;
			break;
		}
	}
}

void Server::deleteChannel( std::string const & name ) {

	if (this->_channels.find(name) != this->_channels.end())
	{
		delete this->_channels[name];
		_channels.erase(name);
	}
}

void Server::exit()
{
    std::cout << "Good Bye " << std::endl;
    for (size_t i = 0; i < this->_users.size(); i++)
    {
		close(this->_users[i]->getFd());
        delete this->_users[i];
    }
    this->_users.clear();
    std::map<std::string, Channel*>::iterator it;
    for (it = this->_channels.begin(); it != this->_channels.end(); it++)
    {
        delete it->second;
    }
    this->_channels.clear();
	std::map<std::string, ACommand*>::iterator it2;
	for (it2 = this->_command.begin(); it2 != this->_command.end(); it2++)
	{
		delete it2->second;
	}
	this->_command.clear();
	close(this->_socket);
}

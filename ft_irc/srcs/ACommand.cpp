#include "ACommand.hpp"
#include "Server.hpp"

ACommand::ACommand( std::string const & name, bool loginRequired ) : _name(name), _loginRequired(loginRequired)
{
}

ACommand::~ACommand()
{
}

bool ACommand::execute( std::vector<std::string> args, User* user, Server* server )
{
    (void)args;
    (void)user;
    (void)server;
    return true;
}

std::string const & ACommand::getName() const
{
    return this->_name;
}

bool ACommand::loginRequired() const
{
	return this->_loginRequired;
}


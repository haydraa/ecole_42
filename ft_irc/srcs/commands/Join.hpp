#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Server;

class Join : public ACommand {

	private:
		void	sendJoinMessage( User* user, Channel* channel, Server* server );
		bool	isValidChannelName(std::string channel_name, Server* server, User* user);
		void	channelCreate(std::string channel_name, Server* server, User* user, std::vector<std::string> &channels_password);

	public:
		Join();
		~Join();
		bool	execute( std::vector<std::string> args, User* user, Server* server );

};

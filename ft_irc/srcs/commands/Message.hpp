#pragma once

#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Message : public ACommand
{

	public:
		Message();
		~Message();
    	bool	execute( std::vector<std::string> args, User* user, Server* server );
		void	sendBroadcastMessage(Server *server, Channel *channel, std::string message, User *origin_user);

};

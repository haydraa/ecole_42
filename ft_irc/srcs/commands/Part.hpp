#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Part : public ACommand {
    
	public:
		Part();
		~Part();
		bool execute( std::vector<std::string> args, User* user, Server* server );
		void leaveChannel( User* user, Server* server, std::string channelName );
    
};

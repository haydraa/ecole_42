#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Invite : public ACommand {
    
	public:
		Invite();
		~Invite();
		bool execute( std::vector<std::string> args, User* user, Server* server );

};

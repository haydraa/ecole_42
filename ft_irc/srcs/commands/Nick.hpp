#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Nick : public ACommand {
    
	public:
		Nick();
		~Nick();
		bool execute( std::vector<std::string> args, User* user, Server* server );
    
};

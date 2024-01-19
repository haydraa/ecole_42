#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Who : public ACommand {
    
	public:
		Who();
		~Who();
		bool execute( std::vector<std::string> args, User* user, Server* server );
    
};

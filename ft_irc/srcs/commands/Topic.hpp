#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Topic : public ACommand {
    
	public:
		Topic();
		~Topic();
		bool execute( std::vector<std::string> args, User* user, Server* server );
    
};

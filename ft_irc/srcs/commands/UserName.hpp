#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class UserName : public ACommand {
    
	public:
		UserName();
		~UserName();
		bool execute( std::vector<std::string> args, User* user, Server* server );
    
};

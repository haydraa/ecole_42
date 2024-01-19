#pragma once

#include <string>
#include "../Channel.hpp"
#include "../Server.hpp"
#include "../User.hpp"
#include "../ACommand.hpp"

class Kick : public ACommand {

	public:
		Kick();
		~Kick();
		bool execute( std::vector<std::string> args, User* user, Server* server );

};

#pragma once

#include "../ACommand.hpp"

class Quit : public ACommand {

	public:
		Quit();
		~Quit();
    	bool	execute( std::vector<std::string> args, User* user, Server* server );

};

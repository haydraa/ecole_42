#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "User.hpp"
#include "Channel.hpp"

class Server;

class ACommand {
    
    private:
        std::string _name;
		bool		_loginRequired;

    public:
        ACommand( std::string const & name, bool loginRequired );
        virtual ~ACommand();

        virtual bool execute( std::vector<std::string> args, User* user, Server* server ) = 0;
        std::string const & getName() const;
		bool loginRequired() const;
};

#include "Part.hpp"

/**
 * NAME : PART
 * USAGE : /part <canal>{,<canal>} [<reason>]
 */
Part::Part() : ACommand( "PART", true )
{

}

Part::~Part()
{

}

bool Part::execute( std::vector<std::string> args, User* user, Server* server ) {
    std::string channelName;

	if (args.empty() || args.size() > 2)
	{
		server->sendMessageError(user->getFd(), "461", "/part <canal>{,<canal>} [<reason>]");
		return false;
	}
    for (size_t i = 0; i < args[0].size(); i++)
	{
        if (args[0][i] != ',')
                channelName = args[0];
        else if (args[0][i] == ',')
        {
            if ((channelName[0] != '#' && channelName[0] != '&') || channelName.size() == 0 || channelName.size() > 200 )
            {
                server->sendMessageError(user->getFd(), "403", channelName + " :No such channel");
                return false;
            }
            leaveChannel(user, server, channelName);
            channelName.clear();
        }
    }
    if ((channelName[0] != '#' && channelName[0] != '&') || channelName.size() == 0 || channelName.size() > 200 )
    {
        server->sendMessageError(user->getFd(), "403", channelName + " :No such channel");
        return false;
    }
    else
    {
        leaveChannel(user, server, channelName);
    }
    return true;
}

void Part::leaveChannel( User* user, Server* server, std::string channelName )
{
    Channel* channelTarget = server->getChannelByName(channelName);

    if (channelTarget == NULL)
    {
        server->sendMessageError(user->getFd(), "403", channelName + " :No such channel");
        return ;
    }

    std::map<User*, int> usersMap = server->getChannelByName(channelName)->getUsers();

    if (channelTarget->containsUser(user) == false)
    {
        server->sendMessageError(user->getFd(), "442", channelName + " :You're not on that channel");
        return ;
    }
    server->sendMessageChannel(channelTarget, ":" + user->getNickname() + " PART " + channelName + "\r\n");
    user->removeChannel(channelName);
    if (usersMap.size() == 1)
        server->deleteChannel(channelName);
    else if (channelTarget->isOp(user) == true && channelTarget->getUsersOpCount() == 1)
    {
        for (std::map<User*, int>::iterator it = usersMap.begin(); it != usersMap.end(); it++)
        {
            if (it->first != user)
			{
                channelTarget->setOp(it->first);
				server->sendMessageChannel(channelTarget, ": 381 " + it->first->getNickname() + " :You are now an IRC operator\r\n");
				break ;
			}
        }
    }
	if (usersMap.size() != 1)
		channelTarget->removeUser(user);
	channelTarget = NULL;
}

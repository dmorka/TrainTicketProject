#ifndef TRAINTICKETPROJECT_CLIENTMANAGER_H
#define TRAINTICKETPROJECT_CLIENTMANAGER_H

#include "ClientRepository.h"

class ClientManager
{
private:
    ClientRepositoryPtr client;

public:
    ClientManager(ClientRepositoryPtr client);

    virtual ~ClientManager();

    bool createClient(ClientPtr client);

    bool removeClient(ClientPtr client);

    string getClientsInfo();

    ClientPtr operator()(const string &personalID);
};

typedef shared_ptr<ClientManager> ClientManagerPtr;

#endif //TRAINTICKETPROJECT_CLIENTMANAGER_H
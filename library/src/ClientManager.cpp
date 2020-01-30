#include <ClientManager.h>

ClientManager::ClientManager(ClientRepositoryPtr client)
        : client(client)
{
    if(client == nullptr)
    {
        throw ParameterException("Error! Client Repository required");
    }
}

ClientManager::~ClientManager() = default;

bool ClientManager::createClient(ClientPtr client)
{
    return this->client->create(client);
}

bool ClientManager::removeClient(ClientPtr client)
{
    return this->client->remove(client);
}

string ClientManager::getClientsInfo()
{
    return this->client->getInfo();
}

ClientPtr ClientManager::operator()(const string &personalID)
{
    return client->find(personalID);
}



#ifndef TRAINTICKETPROJECT_CLIENTREPOSITORY_H
#define TRAINTICKETPROJECT_CLIENTREPOSITORY_H

#include <memory>
#include "Repository.h"
#include "Client.h"

class ClientRepository : public Repository<Client>
{};

typedef shared_ptr<ClientRepository> ClientRepositoryPtr;

#endif //TRAINTICKETPROJECT_CLIENTREPOSITORY_H
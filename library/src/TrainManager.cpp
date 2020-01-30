#include <TrainManager.h>

TrainManager::TrainManager(TrainRepositoryPtr train)
        : train(train)
{
    if(train == nullptr)
    {
        throw ParameterException("Error! Train Repository required");
    }
}

TrainManager::~TrainManager() = default;

bool TrainManager::createTrain(TrainPtr train)
{
    return this->train->create(train);
}

bool TrainManager::removeTrain(TrainPtr train)
{
    return this->train->remove(train);
}

string TrainManager::getTrainsInfo()
{
    return this->train->getInfo();
}

TrainPtr TrainManager::operator()(const string &trainID)
{
    return train->find(trainID);
}
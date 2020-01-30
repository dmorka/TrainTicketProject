#ifndef TRAINTICKETPROJECT_TRAINMANAGER_H
#define TRAINTICKETPROJECT_TRAINMANAGER_H

#include "TrainRepository.h"

class TrainManager
{
private:
    TrainRepositoryPtr train;

public:
    TrainManager(TrainRepositoryPtr train);

    virtual ~TrainManager();

    bool createTrain(TrainPtr train);

    bool removeTrain(TrainPtr train);

    string getTrainsInfo();

    TrainPtr operator()(const string &trainID);
};

typedef shared_ptr<TrainManager> TrainManagerPtr;

#endif //TRAINTICKETPROJECT_TRAINMANAGER_H
#ifndef TRAINTICKETPROJECT_TRAINREPOSITORY_H
#define TRAINTICKETPROJECT_TRAINREPOSITORY_H

#include <memory>
#include "Train.h"
#include "Repository.h"

class TrainRepository : public Repository<Train>
{};

typedef shared_ptr<TrainRepository> TrainRepositoryPtr;

#endif //TRAINTICKETPROJECT_TRAINREPOSITORY_H
#ifndef TRAINTICKETPROJECT_TRAIN_H
#define TRAINTICKETPROJECT_TRAIN_H

#include <string>
#include <vector>
#include <memory>
#include "Carriage.h"
#include "ParameterException.h"
#include "AvailableException.h"

class Train
{
private:
    int trainID;
    string name;
    vector<CarriagePtr> carriages;

public:
    Train(int trainID, const string& name, vector<CarriagePtr> carriages);

    ~Train();

    int getID() const;

    const string &getName() const;

    const vector<CarriagePtr> &getCarriages() const;

    CarriagePtr getCarriage(int index);

    int bookSeat(TravelClass travelClass);

    string getInfo();

    bool addCarriage(const CarriagePtr& carriage);

    bool removeCarriage(const CarriagePtr& carriage);

    bool removeCarriage(int index);

    bool operator==(const Train &rhs) const;

    bool operator!=(const Train &rhs) const;
};

typedef shared_ptr<Train> TrainPtr;

#endif //TRAINTICKETPROJECT_TRAIN_H
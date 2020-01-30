#include <Train.h>
#include <sstream>

using namespace std;

Train::Train(int trainID, const string& name, vector<CarriagePtr> carriages)
        : trainID(trainID), name(name), carriages(carriages)
{
    if(trainID <= 1000)
    {
        throw ParameterException("Error! Train ID > 1000 required");
    }
    if(name == "")
    {
        throw ParameterException("Error! Train name required");
    }
    if(carriages.empty())
    {
        throw ParameterException("Error! Carriages required");
    }
}

Train::~Train() = default;

int Train::getID() const
{
    return trainID;
}

const string &Train::getName() const
{
    return name;
}

const vector<CarriagePtr> &Train::getCarriages() const
{
    return carriages;
}

CarriagePtr Train::getCarriage(int index)
{
    return carriages.at(index);
}

string Train::getInfo()
{
    stringstream info;
    info << "Pociag " << this->getName() << " o numerze " << this->getID() << " sklada sie z " << this->getCarriages().size() << " wagonow.";
    return info.str();
}

int Train::bookSeat(TravelClass travelClass)
{
    if(carriages.empty())
    {
        throw AvailableException("Error! The train has no carriages");
    }
    int temp=0;
    for(int i=0;i<carriages.size();i++)
    {
        if(carriages.at(i)->getCarriageClass() == travelClass)
        {
            for(int j=0;j<=carriages.at(i)->getNumberOfSeats();j++)
            {
                if(carriages.at(i)->getFreeSeats()[j] == 0)
                {
                    temp+=j;
                    carriages.at(i)->setFreeSeat(j,1);
                    return temp;
                }
            }
        }
        temp+=carriages.at(i)->getNumberOfSeats();
    }
    throw AvailableException("Error! Couldn't find a free seat");
}

bool Train::addCarriage(const CarriagePtr& carriage)
{
    carriages.push_back(carriage);
    return true;
}

bool Train::removeCarriage(const CarriagePtr& carriage)
{
    if(carriages.empty())
    {
        throw AvailableException("Error! The train has no carriages");
    }
    for(int i=0;i<=carriages.size();i++)
    {
        if(*carriages.at(i) == *carriage)
        {
            carriages.erase(carriages.begin()+i);
            return true;
        }

    }
    throw AvailableException("Error! Carriage not found!");
}

bool Train::removeCarriage(int index)
{
    if(carriages.size() > index && index >= 0)
    {
        carriages.erase(carriages.begin()+index);
        return true;
    }
    throw AvailableException("Error! Carriage not found!");
}

bool Train::operator==(const Train &rhs) const
{
    if(trainID != rhs.trainID || name != rhs.name)
    {
        return false;
    }

    for(int i = 0; i < carriages.size(); i++)
    {
        if(*carriages[i] != *rhs.carriages[i])
        {
            return false;
        }

    }
    return true;
}

bool Train::operator!=(const Train &rhs) const
{
    return !(rhs == *this);
}
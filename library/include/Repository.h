#ifndef TRAINTICKETPROJECT_REPOSITORY_H
#define TRAINTICKETPROJECT_REPOSITORY_H

#include "Train.h"
#include "Timetable.h"
#include "Ticket.h"
#include "Client.h"
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/lexical_cast.hpp>
#include <typeinfo>
#include "DuplicateException.h"
#include "AvailableException.h"

using namespace std;

template<class T>
class Repository
{
private:
    vector<shared_ptr<T>> elements;
    string className = typeid(T).name();

public:
    Repository();

    virtual ~Repository();

    virtual bool create(shared_ptr<T> element);

    virtual bool remove(shared_ptr<T> element);

    virtual bool remove(int index);

    virtual const vector<shared_ptr<T>> &getElements() const;

    virtual const shared_ptr<T> &getElement(int index) const;

    virtual shared_ptr<T> find(string id);

    virtual string getInfo();

    virtual bool clear();
};

template<class T>
Repository<T>::Repository() = default;

template<class T>
Repository<T>::~Repository() = default;

template<class T>
bool Repository<T>::create(shared_ptr<T> element)
{
    for(auto i : elements)
    {
        if(*i == *element )
        {
            throw DuplicateException("Error! "+className+" already exists");
        }
    }
    elements.push_back(element);
    return true;
}

template <class T>
bool Repository<T>::clear()
{
    if(!elements.empty())
    {
        elements.erase(elements.begin(),elements.end());
        return true;
    }
    throw AvailableException("Error! "+className+" list is empty");
}

template <class T>
bool Repository<T>::remove(shared_ptr<T> element)
{
    if(elements.empty())
    {
        throw AvailableException("Error! "+className+" list is empty");
    }
    for(typename vector<shared_ptr<T>>::iterator i = elements.begin(); i != elements.end(); i++)
    {
        if(*i == element)
        {
            elements.erase(i);
            return true;
        }
    }
    throw AvailableException("Error! "+className+" not found");
}

template <class T>
bool Repository<T>::remove(int index)
{
    if(elements.empty())
    {
        throw AvailableException("Error! "+className+" list is empty");
    }
    if(int(elements.size()) > index || 0 <= index)
    {
        for (typename vector<shared_ptr<T>>::iterator i = elements.begin(); i != elements.end(); i++)
        {
            if (*i == elements[index])
            {
                elements.erase(i);
                return true;
            }
        }
    }
    throw AvailableException("Error! "+className+" not found");
}

template <class T>
const vector<shared_ptr<T>> &Repository<T>::getElements() const
{
    return elements;
}

template <class T>
const shared_ptr<T> &Repository<T>::getElement(int index) const
{
    if(elements.empty() || elements.size() < index)
    {
        throw AvailableException("Error! "+className+" not found");
    }
    return elements.at(index);
}

template <class T>
string Repository<T>::getInfo()
{
    stringstream info;
    for(auto i : elements)
    {
        info<<i->getInfo()<<"\n";
    }
    return info.str();
}

template <class T>
shared_ptr<T> Repository<T>::find(string id)
{
    if(elements.empty())
    {
        throw AvailableException("Error! "+className+" list is empty");
    }
    for(auto i : elements)
    {
        if(boost::lexical_cast<string>(i->getID()) == id) return i;
    }
    throw AvailableException("Error! "+className+" not found");
}


#endif //TRAINTICKETPROJECT_REPOSITORY_H
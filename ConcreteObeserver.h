// ConcreteObeserver.h
// Created by 程潇 on 2018/7/10.
//

#ifndef PRACTICE_CLION_CONCRETEOBESERVER_H
#define PRACTICE_CLION_CONCRETEOBESERVER_H

#include "Obeserver.h"
#include <string>
using namespace std;

class ConcreteObeserver : public Obeserver
{

public:
    ConcreteObeserver(string name);
    virtual ~ConcreteObeserver();
    virtual void update(Subject * sub);

private:
    string m_objName;
    int m_obeserverState;
};


#endif //PRACTICE_CLION_CONCRETEOBESERVER_H

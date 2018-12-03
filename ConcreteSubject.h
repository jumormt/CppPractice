// ConcreteSubject.h
// Created by 程潇 on 2018/7/10.
//

#ifndef PRACTICE_CLION_CONCRETESUBJECT_H
#define PRACTICE_CLION_CONCRETESUBJECT_H


#include "Obeserver.h"
#include <vector>
#include "Subject.h"
#include "string"
using namespace std;

class ConcreteSubject:public Subject
{

public:
    ConcreteSubject(string n);
    virtual int getState();

    virtual void setState(int i);

private:
    int subAState;
    string name;

};


#endif //PRACTICE_CLION_CONCRETESUBJECT_H

//
// Created by 程潇 on 2018/7/10.
//

#ifndef PRACTICE_CLION_SUBJECT_H
#define PRACTICE_CLION_SUBJECT_H


#include "Obeserver.h"
#include <vector>
using namespace std;

class Subject
{

public:
    Subject();
    virtual ~Subject();
    Obeserver *m_Obeserver;

    void attach(Obeserver * pObeserver);
    void detach(Obeserver * pObeserver);
    void notify();

    virtual int getState() = 0;
    virtual void setState(int i)= 0;

private:
    vector<Obeserver*> m_vtObj;
    int subState;

};


#endif //PRACTICE_CLION_SUBJECT_H

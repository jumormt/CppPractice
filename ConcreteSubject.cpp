// ConcreteSubject.cpp
// Created by 程潇 on 2018/7/10.
//

#include "ConcreteSubject.h"
using namespace std;

ConcreteSubject::ConcreteSubject(string n) {
    name = n;
}

int ConcreteSubject::getState(){
    return subAState;
}

void ConcreteSubject::setState(int i){
    subAState = i;
    notify();
}
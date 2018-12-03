// ConcreteObeserver.cpp
// Created by 程潇 on 2018/7/10.
//
#include "ConcreteObeserver.h"
#include <iostream>
#include <vector>
#include "Subject.h"
#include "ConcreteObeserver.h"
using namespace std;

ConcreteObeserver::ConcreteObeserver(string name){
    m_objName = name;
}

ConcreteObeserver::~ConcreteObeserver(){

}

void ConcreteObeserver::update(Subject * sub){
    m_obeserverState = sub->getState();
    cout << "update oberserver[" << m_objName << "] state:" << m_obeserverState << endl;
}
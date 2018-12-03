// Obeserver.h
// Created by 程潇 on 2018/7/10.
//

#ifndef PRACTICE_CLION_OBESERVER_H
#define PRACTICE_CLION_OBESERVER_H
class Subject;

class Obeserver {
public:
    virtual ~Obeserver(){

    }
    virtual void update(Subject * sub) = 0;
};


#endif //PRACTICE_CLION_OBESERVER_H

//
// Created by 76947 on 2017/12/5.
//

#ifndef PRACTICE_CLION_CLASSFILE_H
#define PRACTICE_CLION_CLASSFILE_H
#include <cstring>
#include <iostream>

using namespace std;
class classfile {

};
class human{

public:

    human(char *i);

    char name[10];
    char *sex;

    void set_name(char *nam);

    friend ostream &operator<<(ostream &os, const human &human1);

    char* get_name();
    int age;

private:


};

class woman:public human{

public:
    woman(char *i);
//    void set_level(const int&i){
//        level = i;
//    }
//    int get_level();

private:
//    int level;

};


#endif //PRACTICE_CLION_CLASSFILE_H

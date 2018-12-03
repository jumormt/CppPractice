//
// Created by 76947 on 2017/12/5.
//

#include "classfile.h"

void human::set_name(char *nam){
    strcpy(name,nam);
}

human::human(char *i) {
    strcpy(name,i);
    age = 1;
    cout<<"human";
}

ostream &operator<<(ostream &os, const human &human1) {
    os << "age: " << human1.age;
    return os;
}


woman::woman(char *i):human(i){
    cout<<"woman";
    age = 2;
}

int update(human& wm){
    cout<<wm.name;
    return 0;
}

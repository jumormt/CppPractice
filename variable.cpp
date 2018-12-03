//
// Created by 76947 on 2017/12/5.
//

#include "variable.h"

void multiDArray()
{
    typedef const int ia[4];
    using ia2 = const int(*)[4];
    // 指针函数用法同理

    const int ma[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    const int (*p)[4] = ma;

    for (auto i = (*p); i < (*p)+4; ++i) {
        cout<<*i<<" ";
    }
    cout<<endl;

    for (auto i = ma; i < ma+3; ++i) {
        for (auto j = *i; j < *i+4; ++j)
            cout<<*j<<" ";
    }
    cout<<endl;

    for (auto i = begin(ma); i != end(ma); ++i){
        for (auto j = *i; j != *i+4; ++j)
            cout<<*j<<" ";
    }
    cout<<endl;

    for (ia2 i = ma; i < ma+3; ++i){
        for (const int *j = *i; j < *i + 4; ++j) {
            cout<<*j<<" ";
        }
    }

}

int (*func(int(&a)[10]))[10]{
    return &a;
}

int stuff_info()
{
    manager m1;
    technician t1;
    salesmanager sm1;
    salesman s1;
    char namestr[20];   //输入雇员姓名时首先临时存放在namestr中
    vector < employee* > vchar;   //声明用于保存成员对象的容器
    vchar.push_back(&m1);
    vchar.push_back(&t1);
    vchar.push_back(&sm1);
    vchar.push_back(&s1);
    vector< employee* >::iterator it = vchar.begin();
    for(it=vchar.begin();it!=vchar.end();++it)
    {
        cout<<"请输下一个雇员的姓名：";
        cin>>namestr;
        (*it)->SetName(namestr);        //设置姓名
        (*it)->promote(0);         // 升级
    }
    cout<<"请输入兼职技术人员"<<t1.GetName()<<"本月的工作时数：";
    int ww;
    cin>>ww;
    t1.SetworkHours(ww);        //设置工作时间
    cout<<"请输入销售经理"<<sm1.GetName()<<"所管辖部门本月的销售总额：";
    float sl;
    cin>>sl;
    sm1.setsales(sl);     //设置本月的销售总额
    cout<<"请输入推销员"<<s1.GetName()<<"本月的销售额：";
    cin>>sl;
    s1.setsales(sl);    //设置本月的销售额
    ofstream ofile("F://C++//practice_clion//resource//employee.txt",ios_base::out);     //创建一个输出文件流对象
    for(it=vchar.begin();it!=vchar.end();++it)
    {
        (*it)->pay();
        ofile<<(*it)->GetName()<<"编号"<<(*it)->GetindividualEmpNo()
             <<"级别为"<<(*it)->Getgrade()<<"级，本月工资"
             <<(*it)->GetaccumPay()<<endl;
    }
    ofile.close();
    cout<<"人员信息已存入文件"<<endl;
    cout<<"从文件中读取信息并显示如下："<<endl;
    char line[101];
    ifstream infile("F://C++//practice_clion//resource//employee.txt",ios_base::in);      //创建一个输入文件流对象
    for(it=vchar.begin();it!=vchar.end();++it)
    {
        infile.getline(line,100);
        cout<<line<<endl;
    }
    infile.close();
    return 0;
}

//内存分配终极奥义
void UseRawMemory(){

    void *rawMemory = operator new[](10* sizeof(string));

    string *stringMemory = static_cast<string*>(rawMemory);

    for (int i = 0; i < 10; ++i){
        new (&stringMemory[i]) string("haha\n");
    }

    for (int i = 0; i < 10; ++i){
        cout<<stringMemory[i];
    }
}

// 使用vector更新queue
template <typename T>
void initQueue(vector<T> &vec, queue<T> &que){
    for (auto it = vec.begin();  it != vec.end() ; ++it) {
        que.push(*it);
    }
}


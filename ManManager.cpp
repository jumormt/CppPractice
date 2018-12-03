//
// Created by 76947 on 2018/1/31.
//

#include "ManManager.h"

#include<iostream>
#include<cstring>

using namespace std; //std 标准C++中必须存在的一个名字空间的名字

int employee::employeeNo=1000;  //员工编号的基数1000

employee::employee()
{
    individualEmpNo = employeeNo++;  //新输入的员工编号为目前最大值+1
    grade = 1;  //级别初值为1
    accumPay = 0.0;//月薪总额初值为0
}

employee::~employee()
{}

void employee::promote(int increment)
{
    grade += increment;  //升级，提升的级数由参数increment指定
}

void employee::SetName(char *names)
{
    strcpy(name,names);//设置员工姓名
}

char * employee::GetName()
{
    return name;  //得到员工姓名
}

int employee::GetindividualEmpNo()
{
    return individualEmpNo;  //得到员工编号
}

int employee::Getgrade()
{
    return grade;//得到员工的级别
}

float employee::GetaccumPay()
{
    return accumPay;//得到月薪
}

technician::technician()
{
    hourlyRate=100;//每小时酬金100
}

void technician::SetworkHours(int wh)
{
    workHours = wh;//设置工作时间
}

void technician::pay()
{
    accumPay = hourlyRate*workHours;//计算月薪，按小时计算
}

void technician::promote(int)
{
    employee::promote(2); //提升到2级
}

salesman::salesman()
{
    CommRate=0.04;//销售提成比例4%
}

void salesman::setsales(float sl)
{
    sales=sl;//设置销售额
}

void salesman::pay()
{
    accumPay=sales*CommRate;//月薪=销售提成
}

void salesman::promote(int)
{
    employee::promote(0);//提升到0级
}

manager::manager()
{
    monthlyPay=8000;//固定月薪8000
}

void manager::pay()
{
    accumPay=monthlyPay;//月薪总额=固定月薪数
}

void manager::promote(int)
{
    employee::promote(3);//提升到3级
}

salesmanager::salesmanager()
{
    monthlyPay=5000;
    CommRate=0.005;
}

void salesmanager::pay()
{
    accumPay=monthlyPay+CommRate*sales;//月薪=固定月薪+销售提成
}

void salesmanager::promote(int)
{
    employee::promote(2);// 提升到2级
}

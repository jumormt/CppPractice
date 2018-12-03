//
// Created by 76947 on 2018/1/31.
//

#ifndef PRACTICE_CLION_MANMANAGER_H
#define PRACTICE_CLION_MANMANAGER_H
// 人员信息管理.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<fstream>  //包含文件流头文件

#include<vector>  //包含向量容器头文件
using namespace std;

class employee  //雇员类
{

protected:
    char name[20];  //姓名
    int individualEmpNo;//个人编号
    int grade;//级别
    float accumPay;//与薪总额
    static int employeeNo;//本公司职员编号初值

public:
    employee();//构造函数
    ~employee();//析构函数

    virtual void pay() = 0;//月薪计算函数（纯虚函数）
    virtual void promote(int increament = 0);//升级函数（虚函数）

    void SetName(char *);//设置姓名函数
    char * GetName();//提取姓名函数

    int GetindividualEmpNo();//提取编号函数
    int Getgrade();//提取级别函数
    float GetaccumPay();//提取月薪函数

};


class technician:public employee  //兼职技术人员类
{

private:
    float hourlyRate;  //每小时酬金
    int workHours;//当月工作数

public:
    technician();//构造函数

    void SetworkHours(int wh);//设置工作时间函数
    void pay() override final;//计算月薪函数
    void promote(int) override final;//升级函数

};


class salesman:virtual public employee //兼职销售人员类
{

protected:
    double CommRate;//按销售额提取酬金的百分比
    float sales;//当月销售额

public:
    salesman();//构造函数
    void setsales(float sl);//设置销售额函数
    void pay() override;//计算月薪函数
    void promote(int) override;//升级函数

};


class manager:virtual public employee  //经理类
{

protected:
    float monthlyPay;  //固定月薪

public:
    manager();//构造函数
    void pay() override;//计算酬金函数
    void promote(int) override;//升级函数
};


class salesmanager:public manager,public salesman //销售经理类
{

public:
    salesmanager();  //构造函数
    void pay() override;//计算月薪函数
    void promote(int) override;//升级函数
};




#endif //PRACTICE_CLION_MANMANAGER_H

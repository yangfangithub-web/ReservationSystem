#pragma once


#include <iostream>
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

using namespace std;


class Manager :public Identity {
public:
	Manager();
	Manager(string name, string pwd);

	//选择菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化学生，老师容器
	void initVector();

	//检测添加账号是否重复
	bool checkRepeat(int id, int type);

	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;
private:
	string m_Name;
	string m_Pwd;


};
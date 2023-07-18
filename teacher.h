#pragma once

#include <iostream>
#include "identity.h"
using namespace std;

class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empId, string name, string pwd);

	//显示菜单
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//教师编号
	int m_EmpId;

};
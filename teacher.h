#pragma once

#include <iostream>
#include "identity.h"
using namespace std;

class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empId, string name, string pwd);

	//��ʾ�˵�
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;

};
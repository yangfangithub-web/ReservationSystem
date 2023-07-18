#pragma once

#include <iostream> 
#include <vector>
using namespace std;

#include "identity.h"
#include "computerRoom.h"

class Student :public Identity {
public:
	Student();
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//������ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ����
	int m_Id;

	vector<ComputerRoom> vCom;

};
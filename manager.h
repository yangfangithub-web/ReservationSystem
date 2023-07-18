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

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ��ѧ������ʦ����
	void initVector();

	//�������˺��Ƿ��ظ�
	bool checkRepeat(int id, int type);

	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;
private:
	string m_Name;
	string m_Pwd;


};
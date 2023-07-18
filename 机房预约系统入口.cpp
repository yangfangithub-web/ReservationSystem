#include <stdio.h>
#include <iostream>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <string>
#include <fstream>

using namespace std;
void managerMenu(Identity*& manager);//ǰ������
void studentMenu(Identity*& manager);
void TeacherMenu(Identity*& teacher);

//��¼����
void LoginIn(string fileName, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "ͬѧ��ã����������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "��ʦ��ã���������Ĺ���" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ����֤��¼
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2) {
		//��ʦ��֤��¼
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	else {
		cout << "��֤��¼ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

}

void managerMenu(Identity*& manager) {
	while (true) {
		//����Ա�˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1) {//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student) {
	while (true) {
		//��ʾѧ���˵�
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) {//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");

			return;
		}
	}

}

int main() {

	int select = 0;
	while (true) {


		cout << "====================��ӭ��������ԤԼϵͳ==============================" << endl;
		cout << endl << "��ѡ��������ݣ�" << endl;
		cout << "\t\t---------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|   1. ѧ��                     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|   2. ��ʦ                     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|   3. ����Ա                   |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|   0. �˳�                     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t---------------------------------\n";
		cout << "����������ѡ��";

		cin >> select;

		switch (select) {
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}
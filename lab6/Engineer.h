#pragma once
#include "Worker.h"
using namespace std;

class engineer :public worker // ����������� �����
{
public:
	engineer() : worker() {}

	engineer(const char* NAME, int age1, int EXPERIENCE, string POSITION, string QUALIFICATION, bool AddToList = false) :worker(NAME, age1, EXPERIENCE, POSITION)
	{
		if (AddToList)
		{
			person* p = begin;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
		qualification = QUALIFICATION;
	}
	void show()
	{
		cout << "\n�����: �������";
		cout << "\n���: " << name;
		cout << "\n�������: " << age; 
		cout << "\n���������: " << position;
		cout << "\n���� ������: " << experience;
		cout << "\n������������: " << qualification;
		cout << "\n";
	}
	void input()
	{
		cout << "\n��� ��������: ";
		cin >> name;
		cout << "\n�������:";
		cin >> age;
		cout << "\n���������: ";
		cin >> position;
		cout << "\n���� ������: ";
		cin >> experience;
		cout << "\n������������: ";
		cin >> qualification;
		cout << "\n";
	}
	~engineer()  // ����������
	{
		cout << "engineer object deleted" << endl;
	}
protected:
	string qualification;
};

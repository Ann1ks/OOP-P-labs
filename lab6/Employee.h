#pragma once
#include "Person.h"

using namespace std;
class employee :public person  // ����������� �����
{
public:
	employee() : person() {}

	employee(const char* NAME, int age1,string RANK ,bool AddToList = false) :person(NAME, age1)
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
		rank = RANK;
	}
	void show()
	{
		cout << "\n�����: ��������";
		cout << "\n���: " << name;
		cout << "\n�������: " << age;
		cout << "\n������: " << rank;
		cout << "\n";
	}
	void input()
	{
		cout << "\n��� ���������: ";
		cin >> name;
		cout << "\n�������: ";
		cin >> age;
		cout << "\n������: ";
		cin >> rank;
		cout << "\n";
	}
	~employee()  // ����������
	{
		cout << "employee object deleted" << endl;
	}
protected:
	string rank;
};
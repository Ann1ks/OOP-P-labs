#pragma once
#include "Worker.h"
using namespace std;

class engineer :public worker // ����������� �����
{
public:
	engineer() : worker() {}

	engineer(const char* NAME, int age1, bool AddToList = false) :worker(NAME, age1)
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
	}
	void show()
	{
		cout << "\n�����: �������";
		cout << "\n���: " << name;
		cout << "\n�������:" << age;
		cout << "\n";
	}
	void input()
	{
		cout << "\n��� ��������: ";
		cin >> name;
		cout << "\n������� :";
		cin >> age;
		cout << "\n";
	}
	~engineer()  // ����������
	{
		cout << "engineer object deleted" << endl;
	}
};

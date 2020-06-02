#pragma once
#include <string>
using namespace std;

class worker :public person   // ����������� �����
{
public:
	worker() : person() {}   //��� ����������
	worker(const char* NAME, int age1, int EXPERIENCE, string POSITION, bool AddToList = false) :person(NAME, age1) //� �����������
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
		experience = EXPERIENCE;
		position = POSITION;
	}
	void show()
	{
		cout << "\n�����: �������";
		cout << "\n���: " << name;
		cout << "\n�������: " << age;
		cout << "\n���������: " << position;
		cout << "\n���� ������: " << experience;
		cout << "\n";
	}
	void input()
	{
		cout << "\n��� ��������: ";
		cin >> name;
		cout << "\n�������: ";
		cin >> age;
		cout << "\n���������: ";
		cin >> position;
		cout << "\n���� ������: ";
		cin >> experience;
		cout << "\n";
	}
	~worker()  // ����������
	{
		cout << "worker object deleted" << endl;
	}
protected:
	int experience;
	string position;
};

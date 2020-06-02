#pragma once
#include "Worker.h"
using namespace std;

class engineer :public worker // производный класс
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
		cout << "\nКласс: Инженер";
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age; 
		cout << "\nДолжность: " << position;
		cout << "\nОпыт работы: " << experience;
		cout << "\nКвалификация: " << qualification;
		cout << "\n";
	}
	void input()
	{
		cout << "\nИмя Инженера: ";
		cin >> name;
		cout << "\nВозраст:";
		cin >> age;
		cout << "\nДолжность: ";
		cin >> position;
		cout << "\nОпыт Работы: ";
		cin >> experience;
		cout << "\nКвалификация: ";
		cin >> qualification;
		cout << "\n";
	}
	~engineer()  // деструктор
	{
		cout << "engineer object deleted" << endl;
	}
protected:
	string qualification;
};

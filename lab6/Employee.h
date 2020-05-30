#pragma once
#include "Person.h"

using namespace std;
class employee :public person  // производный класс
{
public:
	employee() : person() {}

	employee(const char* NAME, int age1, bool AddToList = false) :person(NAME, age1)
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
		cout << "\nКласс: Служащий";
		cout << "\nИмя: " << name;
		cout << "\nВозраст:" << age;
		cout << "\n";
	}
	void input()
	{
		cout << "\nИмя Служащего: ";
		cin >> name;
		cout << "\nВозраст :";
		cin >> age;
		cout << "\n";
	}
	~employee()  // деструктор
	{
		cout << "employee object deleted" << endl;
	}
};
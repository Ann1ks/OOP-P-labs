#pragma once
#include "Worker.h"
using namespace std;

class engineer :public worker // производный класс
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
		cout << "\nКласс: Инженер";
		cout << "\nИмя: " << name;
		cout << "\nВозраст:" << age;
		cout << "\n";
	}
	void input()
	{
		cout << "\nИмя Инженера: ";
		cin >> name;
		cout << "\nВозраст :";
		cin >> age;
		cout << "\n";
	}
	~engineer()  // деструктор
	{
		cout << "engineer object deleted" << endl;
	}
};

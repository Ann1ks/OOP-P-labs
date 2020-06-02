#pragma once
#include <string>
using namespace std;

class worker :public person   // производный класс
{
public:
	worker() : person() {}   //без параметров
	worker(const char* NAME, int age1, int EXPERIENCE, string POSITION, bool AddToList = false) :person(NAME, age1) //с параметрами
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
		cout << "\nКласс: Рабочий";
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age;
		cout << "\nДолжность: " << position;
		cout << "\nОпыт работы: " << experience;
		cout << "\n";
	}
	void input()
	{
		cout << "\nИмя Рабочего: ";
		cin >> name;
		cout << "\nВозраст: ";
		cin >> age;
		cout << "\nДолжность: ";
		cin >> position;
		cout << "\nОпыт Работы: ";
		cin >> experience;
		cout << "\n";
	}
	~worker()  // деструктор
	{
		cout << "worker object deleted" << endl;
	}
protected:
	int experience;
	string position;
};

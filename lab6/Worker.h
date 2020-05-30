#pragma once
using namespace std;

class worker :public person   // производный класс
{
public:
	worker() : person() {}   //без параметров
	worker(const char* NAME, int age1, bool AddToList = false) :person(NAME, age1) //с параметрами
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
		cout << "\nКласс: Рабочий";
		cout << "\nИмя: " << name;
		cout << "\nВозраст:" << age;
		cout << "\n";
	}
	void input()
	{
		cout << "\nИмя Рабочего: ";
		cin >> name;
		cout << "\nВозраст :";
		cin >> age;
		cout << "\n";
	}
	~worker()  // деструктор
	{
		cout << "worker object deleted" << endl;
	}
};

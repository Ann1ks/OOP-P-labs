#pragma once

using namespace std;

class person  // базовый класс
{
public:
	static  person* begin;   //указатель на начало списка
	person* next = NULL;
	static void ShowList()  //список
	{
		person* p = begin;
		while (p)
		{
			p->show();
			p = p->next;
		}
	}
	person()  //без параметров
	{
		name = new char[81];
	}
	person(const char* NAME, int age1)  //с параметрами
	{
		// выделение памяти для name. размер выделяемой памяти = длина строки NAME
		name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);
		age = age1;

	}
	~person()  // деструктор
	{
		cout << "Person object deleted" << endl;
	}
	virtual void show() = 0;  //Чистая виртуальная функция
	virtual void input() = 0;

protected:
	char* name;
	int age;
};


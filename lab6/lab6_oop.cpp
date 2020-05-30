#include "pch.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Employee.h"
#include"Worker.h"
#include"Engineer.h"

using namespace std;

person* person::begin = NULL; //Инициализация статической компоненты

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	worker* a1;
	employee* a2;
	engineer* a3;
	a1 = new worker;
	a2 = new employee;
	a3 = new engineer;
	a1->input();
	a2->input();
	a3->input();
	cout << "---------------------------------\n";
	person::begin = a1;
	a1->next = a2;
	a2->next = a3;
	engineer* x4 = new engineer("Dimon-patron", 20, true); // Создание объекта класса
	person::ShowList();

	return 0;
}

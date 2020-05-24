// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("D:\\input.txt");
	ofstream fout("D:\\output.txt");
	string a;
	while (getline(fin, a))//считываем строки с файла
	{
		for (int i = 0; i < a.length(); i++)
		{
			if ((a[i] == '/') && (a[i + 1] == '/'))//проверяем на наличие коментариев
			{
				a.erase(i, a.length());//удаляем коментарии
			}
		}
		fout << a << endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}

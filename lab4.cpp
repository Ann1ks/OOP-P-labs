// ConsoleApplication1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
	while (getline(fin, a))//��������� ������ � �����
	{
		for (int i = 0; i < a.length(); i++)
		{
			if ((a[i] == '/') && (a[i + 1] == '/'))//��������� �� ������� �����������
			{
				a.erase(i, a.length());//������� ����������
			}
		}
		fout << a << endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}

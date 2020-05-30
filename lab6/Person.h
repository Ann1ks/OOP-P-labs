#pragma once

using namespace std;

class person  // ������� �����
{
public:
	static  person* begin;   //��������� �� ������ ������
	person* next = NULL;
	static void ShowList()  //������
	{
		person* p = begin;
		while (p)
		{
			p->show();
			p = p->next;
		}
	}
	person()  //��� ����������
	{
		name = new char[81];
	}
	person(const char* NAME, int age1)  //� �����������
	{
		// ��������� ������ ��� name. ������ ���������� ������ = ����� ������ NAME
		name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);
		age = age1;

	}
	~person()  // ����������
	{
		cout << "Person object deleted" << endl;
	}
	virtual void show() = 0;  //������ ����������� �������
	virtual void input() = 0;

protected:
	char* name;
	int age;
};


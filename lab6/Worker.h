#pragma once
using namespace std;

class worker :public person   // ����������� �����
{
public:
	worker() : person() {}   //��� ����������
	worker(const char* NAME, int age1, bool AddToList = false) :person(NAME, age1) //� �����������
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
		cout << "\n�����: �������";
		cout << "\n���: " << name;
		cout << "\n�������:" << age;
		cout << "\n";
	}
	void input()
	{
		cout << "\n��� ��������: ";
		cin >> name;
		cout << "\n������� :";
		cin >> age;
		cout << "\n";
	}
	~worker()  // ����������
	{
		cout << "worker object deleted" << endl;
	}
};

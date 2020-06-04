#include <iostream>
#include <math.h>
#include <vector>

int main() {
	setlocale(0, "RUS");
	std::vector<double> values;
	std::vector<double> results;
	double summ = 0;
	int countNeg = 0;
	rand();
	std::vector<double>::iterator iter, firstNeg, secondNeg;
	for (int i = 0; i < 10; i++)
		if (i % 5 == 0)
			values.push_back(0);
		else
			values.push_back(-10 + rand() % 20);
	for (double element : values) // ��������� � ������ ������������� ��������
		if (element < 0)
			results.push_back(element);
	for (double element : values) // ��������� � ������ ������� ��������
		if (element == 0)
			results.push_back(element);
	for (double element : values) // ��������� � ������ ������������� ��������
		if (element > 0)
			results.push_back(element);

	std::cout << "�������� ������������������:" << std::endl;
	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << " | ";
	std::cout << std::endl;

	std::cout << "������� #1:" << std::endl;
	for (int i = 0; i < results.size(); i++)
		std::cout << results[i] << " | ";

	firstNeg = values.begin();
	secondNeg = values.begin();
	for (iter = values.begin(); iter != values.end(); iter++) { // ���� ������ � ������ ������������� ��������
		if (*iter < 0) {
			switch (countNeg)
			{
			case 0:
				firstNeg = iter;
				countNeg++;
				break;
			case 1:
				secondNeg = iter;
				countNeg++;
				break;
			default:
				break;
			}
			if (countNeg >= 2)
				break;
		}
	}
	std::cout << "\n������ ���.: " << *firstNeg << "; ������ ���.: " << *secondNeg << std::endl;
	for (iter = ++firstNeg; iter < secondNeg; iter++) {
		summ += *iter;
	}

	std::cout << "\n������� #2(������������ �������� ������������������). �����: " << summ << std::endl;
	return 0;
}

#include <iostream>
#include "chset.h"

int main()
{
	chset set1;
	chset set2;
	chset set3;
	set1.input(3);
	set2.input(3);
	set1.print();
	set2.print();
	set1 = set1 - 'A';
	set2 = set2 - 'A';
	set3 = set1 * set2;
	set1.print();
	set2.print();
	set3.print();
	if (set1 < set2)
		std::cout << "Set1 < set2" << std::endl;
	else
		std::cout << "Set1 >= set2" << std::endl;
	return 0;
}
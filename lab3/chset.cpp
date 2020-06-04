#include "chset.h"
#include <iostream>

chset::chset(const chset& chset) {
	value = new char[chset.count];
	count = chset.count;
	for (int i = 0; i < count; i++)
		value[i] = chset.value[i];
}

void chset::input(int size) {
	char key;
	for (int k = 0; k < size; k++) {
		std::cout << "Enter element #" << k << ": ";
		std::cin >> key;
		this->push(key);
	}
}

void chset::print() {
	for (int i = 0; i < count; i++)
		std::cout << value[i] << "\t";
	std::cout << "\nSize: " << count << "\n" << std::endl;
}

bool chset::subset(const char item) {
	for (int i = 0; i < count; i++) {
		if (value[i] == item)
			return 1;
	}
	return 0;
}

bool chset::subset(const chset& chset) {
	bool find = false;
	if (count >= chset.count) {
		for (int i = 0; i < chset.count; i++) {
			for (int k = 0; k < count; k++) {
				if (value[k] == chset.getChar(i)) {
					find = true;
				}
			}
			if (!find)
				return 0;
			find = false;
		}
		return 1;
	}
	else
		return 0;
}

void chset::push(const char item)
{
	char* p2;
	p2 = value;
	bool isFind = false;

	try {
		if (subset(item))
			return;
		value = new char[count + 1];
		for (int i = 0; i < count; i++)
			value[i] = p2[i];
		for (int i = 0; i < count; i++) {
			if (item < value[i])
			{
				for (int k = count; k > i; k--)
				{
					value[k] = value[k - 1];
				}
				value[i] = item;
				isFind = true;
				break;
			}
		}
		if (!isFind)
			value[count] = item;
		count++;
		if (count > 0)
			delete[] p2;
	}
	catch (std::bad_alloc e) {
		std::cout << e.what() << std::endl;
	}
}

chset::~chset() {
	if (count > 0)
		delete[] value;
}

void chset::remove(const char item) {
	if (count < 1)
		return;
	if (!subset(item))
		return;
	try {
		char* val2;
		val2 = new char[count - 1];
		for (int i = 0; i < count - 1; i++)
			if (value[i] != item)
				val2[i] = value[i];
			else
			{
				for (int k = i; k < count - 1; k++)
					val2[k] = value[k + 1];
				break;
			}
		count--;
		if (count > 0)
			delete[] value;
		value = val2;
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
}

chset& chset::operator=(const chset& obj) {
	char* val2;

	try {
		val2 = new char[obj.count];
		if (count > 0)
			delete[] value;
		value = val2;
		count = obj.count;
		for (int i = 0; i < count; i++)
			value[i] = obj.value[i];
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

chset& chset::operator-=(const char item) {
	remove(item);
	return *this;
}

chset& chset::operator*=(const chset& _chset) {
	chset* buff = new chset();
	for (int i = 0; i < _chset.size(); i++) {
		if (subset(_chset.value[i])) {
			buff->push(_chset.value[i]);
		}
	}
	*this = *buff;
	return *this;
}


chset operator-(const chset& _chset, const char item) {
	chset buff(_chset);
	buff -= item;
	return buff;
}

chset operator*(const chset& _chset, const chset& _chset2) {
	chset buff(_chset);
	buff *= _chset2;
	return buff;
}
bool chset::operator<(const chset& chset) {
	return size() < chset.size();
}
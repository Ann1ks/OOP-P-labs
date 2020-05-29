#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;


 void main() {
	ifstream fin("D:\\input.txt");
	if (!fin.is_open()) {
		cout << "cant open file";
	}
	else
	{
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		fin.seekg(0, ios_base::beg);
		char *buf = new char[size + 1];
		fin.read(buf, size);
		ofstream fout("D:\\output.txt", ios::trunc);
		for (int i = 0; i < size; i++) {
			if (buf[i] == '/' && buf[i + 1] == '/') {
				while (buf[i + 1] != '\n') i++;
				continue;
			}
			if (buf[i] == '/' && buf[i + 1] == '*') {
				i += 2;
				while (buf[i] != '*' || buf[i + 1] != '/') i++;
				i += 2;
				continue;
			}
			fout << buf[i];
		}
		fin.close();
		fout.close();
	}
}

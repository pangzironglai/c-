/*
stringstream �ĳ����÷�
1.�������͵�ת��
2.����ַ���ƴ��
3.stringstream�����
*/
#include"pch.h"
#include<string>
#include<sstream>
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	/*
	1.�ַ����������Ļ���ת��
	
	stringstream sstream;
	int value = 100;
	string str;
	sstream << value;
	sstream >> str;
	printf("11");
	*/

	/*
	����ַ�����ƴ��
	*/
	stringstream sstream;
	sstream << "first string";
	sstream << "second string";
	cout << "result: " << sstream.str() << "\n";
	system("pause");
	return 0;
	

}
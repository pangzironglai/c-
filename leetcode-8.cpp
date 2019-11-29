/*
stringstream 的常见用法
1.数据类型的转化
2.多个字符串拼接
3.stringstream的清空
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
	1.字符串与整数的互相转换
	
	stringstream sstream;
	int value = 100;
	string str;
	sstream << value;
	sstream >> str;
	printf("11");
	*/

	/*
	多个字符串的拼接
	*/
	stringstream sstream;
	sstream << "first string";
	sstream << "second string";
	cout << "result: " << sstream.str() << "\n";
	system("pause");
	return 0;
	

}
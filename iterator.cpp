#include<string>

/*
使用iterator 输出 字符串中字符
*/
int main()
{
  string str;
  cin >> str;
  string :: iterator ptr = str.begin();
  while(ptr != str.end())
  {
      cout << *(ptr++)<< "\n"; 
  }
  return 0;
}


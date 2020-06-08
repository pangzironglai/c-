#include<iostream>
using namespace std;

class Clock {
private:
	int hour, minus, second;
public:
	Clock(int h, int m, int s) :hour(h), minus(m), second(s) {};
	Clock() :Clock(0, 0, 0) {};
	void showTime() {
		cout << hour << ':' << minus << ':' << second << endl;
	}
	// ǰ��++�� ����++c. ���ص������õ�ֵ������ֵ��
	Clock & operator ++() {  
		second++;
		if (second >= 60) {
			minus++;
			if (minus >= 60) {
				hour++;
				if (hour >= 24)
					hour = hour % 24;
			}
		}
		return *this;
	}
	Clock operator ++(int) {  //����++�����ص�����ֵ
		Clock old;
		++(*this);
		return old;
	}
};


int main() {
	Clock c(23, 59, 59);
	c.showTime();
	(c++).showTime();
	(++c).showTime();
}
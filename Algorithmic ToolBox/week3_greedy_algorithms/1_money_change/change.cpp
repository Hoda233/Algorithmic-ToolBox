#include <iostream>

int get_change(int m) {
	//write your code here
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;

	n1 = m / 10;      //n1=28/10=2
	m -= n1 * 10;    //m=28-2*10=8
	n2 = m / 5;      //n2=8/5=1
	m -= n2 * 5;     //m=8-1*5=3
	n3 = m;          //n3=m/1;

	int n = 0;
	n = n1 + n2 + n3;
	return n;


}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}


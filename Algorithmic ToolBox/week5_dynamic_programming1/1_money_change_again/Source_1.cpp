#include <iostream>
using namespace std;

int get_change(int m)
{
	//write your code here
	int* coins = new int[m];
	coins[0] = 0;
	int min_coins = INT8_MAX;
	int m1 = INT8_MAX;

	for (int i = 1; i <= m; i++)
	{
		min_coins = INT8_MAX;
		if (i >= 1)
		{
			m1 = coins[i - 1] + 1;
			if (m1 <= min_coins)
				min_coins = m1;
		}
		if (i >= 3)
		{
			m1 = coins[i - 3] + 1;
			if (m1 <= min_coins)
				min_coins = m1;
		}
		if (i >= 4)
		{
			m1 = coins[i - 4] + 1;
			if (m1 <= min_coins)
				min_coins = m1;
		}
		coins[i] = min_coins;
	}
	return coins[m] ;
}

int main() 
{
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
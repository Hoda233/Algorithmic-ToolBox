#include <iostream>
#include <string>
#include<vector>
using namespace std;
using std::vector;
using std::string;

int edit_distance(const string& str1, const string& str2)
{
	//write your code here
	int** D = new int* [str1.size() + 1];
	for (int i = 0; i < str1.size() + 1; i++)
	{
		D[i] = new int[str2.size() + 1];
	}


	int insertion = 0;
	int	deletion = 0;
	int	match = 0;
	int	mismatch = 0;
	for (int i = 0; i <= str1.size(); i++)
	{
		for (int j = 0; j <= str2.size(); j++)
		{
			if (i == 0)
				D[i][j] = j;
			else if (j == 0)
				D[i][j] = i;
			else
			{
				insertion = D[i][j - 1] + 1;
				deletion = D[i - 1][j] + 1;
				match = D[i - 1][j - 1];
				mismatch = D[i - 1][j - 1] + 1;

				if (str1[str1.size() - i] == str2[str2.size() - j])
					D[i][j] = D[i - 1][j - 1];
				else
					D[i][j] = min(insertion, min(deletion, mismatch));
			}
		}
	}

	/*for (int i = 0; i <= str1.size(); i++)
	{
		for (int j = 0; j <= str2.size(); j++)
		{
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}*/
	return D[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
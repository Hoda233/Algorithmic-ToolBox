#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max1 = -1;
	int max2 = -1;
	if (arr[0] >= arr[1])
	{
		max1 = arr[0];
		max2 = arr[1];
	}
	else
	{
		max1 = arr[1];
		max2 = arr[0];
	}
	for (int i = 2; i < n; i++)
	{
		if (arr[i] >= max1)
		{
			max2 = max1;   max1 = arr[i];
		}
		else if (arr[i] >= max2)
		{
			max2 = arr[i];
		}
	}

	long long product = ((long long)max1) * ((long long)max2);
	cout << product;

	return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers); << "\n";
    return 0;
}*/

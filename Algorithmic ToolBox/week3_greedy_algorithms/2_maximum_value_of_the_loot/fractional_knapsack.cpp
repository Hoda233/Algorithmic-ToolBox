#include <iostream>
#include <vector>
#include <algorithm>    
#include <functional>
using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    // write your code here
    int s = values.size();
    vector<double> arr(s);
    for (int i = 0; i < s; i++)
    {
        arr[i] = double(values[i]) / weights[i];  // convert one to double
    }

    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap(weights[j], weights[j + 1]);  //to make every weight corresponding to its v\w
            }
        }
    }

    for (int i = 0; i < s; i++)
    {
        if (capacity == 0)
            return value;
        else
        {
            double a = 0;
            a = min(weights[i], capacity); //take all weight or until its full

            value += arr[i] * a;
            weights[i] -= a;
            capacity -= a;
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
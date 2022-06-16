#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        }
        else if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
vector<int> calculator(int n, int& operation)
{
    vector<int> operations(n + 1);

    operations[0] = 0;
    operations[1] = 0;


    int operation1 = INT_MAX;
    int operation2 = INT_MAX;
    int operation3 = INT_MAX;

    for (int i = 2; i <= n; i++)
    {
        operation1 = INT_MAX;
        operation2 = INT_MAX;
        operation3 = INT_MAX;

        if (i % 3 == 0)
        {
            operation1 = operations[i / 3];
        }
        if (i % 2 == 0)
        {
            operation2 = operations[i / 2];
        }
        operation3 = operations[i - 1];

        operations[i] = min(operation1, min(operation2, operation3)) + 1;
    }
    operation = operations[n];

    vector<int> sequence;
    int min_op = INT_MAX;
    sequence.push_back(n);
    while (n > 1)
    {
        operation1 = INT_MAX;
        operation2 = INT_MAX;
        operation3 = INT_MAX;

        if (n % 3 == 0)
            operation1 = operations[n / 3];
        if (n % 2 == 0)
            operation2 = operations[n / 2];
        operation3 = operations[n - 1];

        min_op = min(operation1, min(operation2, operation3));

        if (min_op == operation1)
            n /= 3;
        else if (min_op == operation2)
            n /= 2;
        else if (min_op == operation3)
            n -= 1;

        sequence.push_back(n);
    }

    reverse(sequence.begin(), sequence.end());
    return sequence;
}
int main()
{
    int n;
    std::cin >> n;
    /*vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }*/
    int operation = 0;
    vector<int> sequence = calculator(n, operation);
    cout << operation << "\n";
    for (size_t i = 0; i < sequence.size(); ++i)
        std::cout << sequence[i] << " ";

}

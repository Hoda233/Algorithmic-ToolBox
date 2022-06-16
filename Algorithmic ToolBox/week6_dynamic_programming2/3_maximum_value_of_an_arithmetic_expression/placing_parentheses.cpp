#include <iostream>
#include<algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
}

long long get_maximum_value(const string& exp) {
    //write your code here
    int length = exp.size();
    int n = (length + 1) / 2;

    long long** M = new long long* [n];
    for (int i = 0; i < n; i++)
        M[i] = new long long[n];

    long long** m = new long long* [n];
    for (int i = 0; i < n; i++)
        m[i] = new long long[n];

    for (int i = 0; i < n; i++)
    {
        m[i][i] = stoll(exp.substr(2 * i, 1));
        M[i][i] = stoll(exp.substr(2 * i, 1));
    }

    for (int s = 0; s < n - 1; s++)
    {
        for (int i = 0; i < n - s - 1; i++)
        {
            int j = i + s + 1;
            long long Min = LLONG_MAX;
            long long Max = LLONG_MIN;
            for (int k = i; k < j; k++)
            {
                long long a = eval(M[i][k], M[k + 1][j], exp[2 * k + 1]);
                long long b = eval(M[i][k], m[k + 1][j], exp[2 * k + 1]);
                long long c = eval(m[i][k], M[k + 1][j], exp[2 * k + 1]);
                long long d = eval(m[i][k], m[k + 1][j], exp[2 * k + 1]);

                Max = max(Max, max(a, max(b, max(c, d))));
                Min = min(Min, min(a, min(b, min(c, d))));
            }
            M[i][j] = Max;
            m[i][j] = Min;
        }
    }

    return M[0][n - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
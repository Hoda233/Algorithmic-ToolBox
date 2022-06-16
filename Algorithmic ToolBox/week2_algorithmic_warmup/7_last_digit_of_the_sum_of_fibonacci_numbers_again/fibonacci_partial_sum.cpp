#include <iostream>
#include <vector>
using std::vector;


int pisano(int m)  
{
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < m * m; i++)
    {
        int temp = 0;
        temp = b;
        b = (a + b) % m;
        a = temp;

        if (a == 0 && b == 1)
            c = i + 1;
    }
    return c;
}
long long get_fibonacci_huge_fast(long long n, long long m)
{

    n = n % pisano(m);

    long long a = 0;
    long long b = 1;

    if (n <= 1)
        return n;


    for (int i = 0; i < n - 1; i++)
    {
        long long temp = 0;
        temp = b;
        b = (a + b) % m;
        a = temp;
    }
    return b % m;
}

int get_fibonacci_partial_sum_fast(long long m, long long n) {

    int a = 0;
    if (n <= 1)
        a = n;
    else
        a = (get_fibonacci_huge_fast(n, 10) * 2 + get_fibonacci_huge_fast(n - 1, 10) - 1) % 10;

    int b = 0;
    if (m <= 1)
        b = 0;
    else
        b = (get_fibonacci_huge_fast(m - 1, 10) * 2 + get_fibonacci_huge_fast(m - 1 - 1, 10) - 1) % 10;

    if (a >= b)
        return a - b;
    else
        return (10 + a) - b;
}
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

}
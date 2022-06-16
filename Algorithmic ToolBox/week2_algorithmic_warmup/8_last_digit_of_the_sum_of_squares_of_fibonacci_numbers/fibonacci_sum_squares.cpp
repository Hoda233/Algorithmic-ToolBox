#include <iostream>
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
long long get_fibonacci_huge_fast(long long n, long long m) //n=15 m=3 p=8  n=7
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
int fibonacci_sum_squares_fast(long long n)
{
    if (n <= 1)
        return n;

    return (get_fibonacci_huge_fast(n, 10) * get_fibonacci_huge_fast(n + 1, 10)) % 10;
}
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);

}

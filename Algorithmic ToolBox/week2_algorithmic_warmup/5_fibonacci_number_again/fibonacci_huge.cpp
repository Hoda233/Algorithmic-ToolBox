#include <iostream>
int pisano(int m)  //get period m=3 p=8
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
long long get_fibonacci_huge_fast(long long n, long long m) //n=15 m=3 p=8  n=7  0 1 1 2 0 2 2 1
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


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
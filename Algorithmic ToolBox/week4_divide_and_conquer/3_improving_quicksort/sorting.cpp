#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct pair
{
    int m1;
    int m2;
};

pair partition3(vector<int>& a, int l, int r)
{
    pair m;
    int x = a[l];
    int j = l;
    int k = r;
    int i = l + 1;
    while (i <= k)
    {
        if (a[i] < x)
        {
            swap(a[i], a[j]);
            j++;
            i++;
        }
        else if (a[i] > x)
        {
            swap(a[i], a[k]);
            k--;
        }
        else
        {
            i++;
        }
    }
    m.m1 = j;
    m.m2 = k;
    return m;
}
int partition2(vector<int>& a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}
void randomized_quick_sort3(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    pair m = partition3(a, l, r);

    randomized_quick_sort3(a, l, m.m1 - 1);
    randomized_quick_sort3(a, m.m2 + 1, r);
}
void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);

    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    // randomized_quick_sort(a, 0, a.size() - 1);
    randomized_quick_sort3(a, 0, a.size() - 1);

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
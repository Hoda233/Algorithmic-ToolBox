#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int>& a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    //write your code here

}
int majority(vector<int> a, int left, int right)
{
    sort(a.begin(), a.end());
    int index = 0;
    int count = 1;
    while (index < a.size() - 1)
    {
        if (a[index + 1] == a[index])
        {
            count++;
            if (count > (a.size() / 2))
            {
                return 1;
            }
            index++;
        }
        else
        {
            index++;
            count = 1;
        }
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    // std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
    std::cout << majority(a, 0, a.size() - 1) << '\n';
}

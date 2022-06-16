#include<iostream>
using namespace std;
#include <vector>
using std::vector;

int binary_duplicate(const vector<int>& a, int x) //return first occurance
{
    int left = 0, right = (int)a.size() - 1;
    //write your code here
    if (x < a[0] || x > a[a.size() - 1])
    {
        return -1;
    }
    else
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (x == a[mid] && mid == 0)      //already the first occ.
                return mid;
            else  if (x == a[mid] && x > a[mid - 1]) //check if it is bigger than previous number
                return mid;
            else  if (x > a[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        //std::cout << linear_search(a, b[i]) << ' ';
        std::cout << binary_duplicate(a, b[i]) << ' ';
    }
}
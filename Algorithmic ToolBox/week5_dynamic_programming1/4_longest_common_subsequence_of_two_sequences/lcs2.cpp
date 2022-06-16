#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using std::vector;

int lcs2(vector<int>& a, vector<int>& b) {
    //write your code here
    int m = a.size();
    int n = b.size();

    int** D = new int* [m + 1];
    for (int i = 0; i <= m; i++)
    {
        D[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        D[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        D[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]); 
        }
    }
    /*for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }*/
    return D[m][n];
    // return std::min(std::min(a.size(), b.size()), c.size()); ??????????????????????????????????????????
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}


#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using std::vector;

int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
    //write your code here
    int x = a.size();
    int y = b.size();
    int z = c.size();

    int*** D = new int** [x + 1];
    for (int i = 0; i <= x; i++)
    {
        D[i] = new int* [y + 1];
        for (int j = 0; j <= y; j++)
        {
            D[i][j] = new int[z + 1];
        }
    }

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            for (int k = 0; k <= z; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    D[i][j][k] = 0;

                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) //if(a == b == c)
                    D[i][j][k] = D[i - 1][j - 1][k - 1] + 1;

                else
                    D[i][j][k] = max(max(D[i - 1][j][k], D[i][j - 1][k]), D[i][j][k - 1]);
            }
        }
    }
    return D[x][y][z];
    // return std::min(std::min(a.size(), b.size()), c.size());
}


int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using std::vector;
int partition3(vector<int>& A)
{
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }
    if (sum % 3 != 0)
        return 0;

    int partition = sum / 3;
    int*** D = new int** [A.size() + 1];
    for (int i = 0; i < A.size() + 1; i++)
    {
        D[i] = new int* [partition + 1];
        for (int j = 0; j < partition + 1; j++)
            D[i][j] = new int[partition + 1];
    }
    for (int i = 0; i < A.size() + 1; i++)
    {
        for (int j = 0; j < partition + 1; j++)
        {
            for (int k = 0; k < partition + 1; k++)
            {
                if (i == 0)
                {
                    if (j == 0 && k == 0)
                        D[i][j][k] = true;
                    else
                        D[i][j][k] = false;
                }
                else
                {
                    bool a = D[i - 1][j][k];
                    bool b = (j >= A[i - 1] && D[i - 1][j - A[i - 1]][k]);
                    bool c = (k >= A[i - 1] && D[i - 1][j][k - A[i - 1]]);
                    D[i][j][k] = a || b || c;
                }
            }
        }
    }
    int result = D[A.size()][partition][partition];
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
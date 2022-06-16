#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int>& w) {
    //write your code here
    int current_weight = 0;
    for (size_t i = 0; i < w.size(); ++i) {
        if (current_weight + w[i] <= W) {
            current_weight += w[i];
        }
    }
    return current_weight;
}
int optimalweight(int W, const vector<int>& w) {
    //write your code here
    int** D = new int* [w.size() + 1];
    for (int i = 0; i < w.size() + 1; i++)
        D[i] = new int[W + 1];

    for (int i = 0; i < w.size() + 1; i++)
        D[i][0] = 0;
    for (int j = 0; j < W + 1; j++)
        D[0][j] = 0;

    for (int i = 1; i < w.size() + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] <= j)
                D[i][j] = max(D[i - 1][j - w[i - 1]] + w[i - 1], D[i - 1][j]);
            else
                D[i][j] = D[i - 1][j];
        }
    }
    return D[w.size()][W];
}


int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    // std::cout << optimal_weight(W, w) << '\n';
    std::cout << optimalweight(W, w) << '\n';

}
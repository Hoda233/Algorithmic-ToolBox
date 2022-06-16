#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
    for (int i = 1; i <= n; i++)
    {
        if (n - i > i)                      // 30
        {                                   //-1=29   29>1   1
            summands.push_back(i);         //-2=27    27>2   2
            n -= i;                       //-3=24     24>3   3
        }                                 //-4=20     20>4   4
        else                             //-5=15      15>5   5
        {                                //-6=9       9>6    6
            summands.push_back(n);       //-7=2       2<7    9
            break;
        }
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
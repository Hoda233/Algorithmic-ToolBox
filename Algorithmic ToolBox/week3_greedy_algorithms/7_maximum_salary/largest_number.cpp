#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;




bool IsGreaterOrEqual(string digit1, string digit2)  //79 798
{
    string s1 = digit1 + digit2;  //79 798
    string s2 = digit2 + digit1; //798 79
    string max = s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] > s2[i])
        {
            max = s1;
            break;
        }
        else if (s1[i] < s2[i])
        {
            max = s2;
            break;
        }
    }


    if (max == s1)
        return true;
    else
        return false;

   

}


string largest_number(vector<string> a) {
    //write your code here
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < a.size() - i - 1; j++)
        {
            if (IsGreaterOrEqual(a[j + 1], a[j]))  //54 55    if(a[j]<a[j+1]) swap
            {
                swap(a[j], a[j + 1]);
            }

        }
    }

    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
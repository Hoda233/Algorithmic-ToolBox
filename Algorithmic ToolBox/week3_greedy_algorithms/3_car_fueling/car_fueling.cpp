#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    // write your code here
    int* arr = new int[stops.size() + 2];  //0 ---> s+1 
    arr[0] = 0;
    for (int i = 1; i <= stops.size(); i++)
    {
        arr[i] = stops[i - 1];
    }
    arr[stops.size() + 1] = dist;



    int current_stop = 0;
    int last_stop = 0;
    int num = 0;
    while (current_stop <= stops.size())
    {
        last_stop = current_stop;
        while (current_stop <= stops.size() && arr[current_stop + 1] - arr[last_stop] <= tank)
        {
            current_stop++;
        }
        if (last_stop == current_stop)  //stops[current_stop + 1] - stops[current_stop] > tank
            return -1;
        if (current_stop <= stops.size())
            num++;
    }
    return num;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
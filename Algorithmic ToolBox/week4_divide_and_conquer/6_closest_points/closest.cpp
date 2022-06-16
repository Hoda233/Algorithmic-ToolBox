#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::min;

int partition2(vector<int>& a, vector<int>& b, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
            swap(b[i], b[j]);

        }
    }
    swap(a[l], a[j]);
    swap(b[l], b[j]);

    return j;
}
void randomized_quick_sort(vector<int>& a, vector<int>& b, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    swap(b[l], b[k]);

    int m = partition2(a, b, l, r);

    randomized_quick_sort(a, b, l, m - 1);
    randomized_quick_sort(a, b, m + 1, r);
}
double min_dist(int x1, int y1, int x2, int y2)
{
    return  sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
double naive_solution(vector<int> x, vector<int> y, int start, int end)
{
    double min = TMP_MAX;
    //cout << "\n naive in\n" << start << "  " << end << " \n";
    for (int i = start; i <= end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (min_dist(x[i], y[i], x[j], y[j]) < min)
            {
                //cout<<"dist " << min_dist(x[i], y[i], x[j], y[j]) << " ";
                min = min_dist(x[i], y[i], x[j], y[j]);
                //cout << "min " << min << " ";

            }
        }
    }

    return min;
}
double strip_closest(vector<int> x, vector<int> y, double d)
{
    float min = d;
   randomized_quick_sort(y, x, 0, x.size() - 1); 

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = i + 1; j < x.size() && (y[j] - y[i]) < min; j++)
        {
            if (min_dist(x[i], y[i], x[j], y[j]) < min)
                min = min_dist(x[i], y[i], x[j], y[j]);
        }
    }
    return min;
}

double closet(vector<int> x, vector<int> y, int start, int end)
{
    if (end - start + 1 <= 3)
    {
        //cout << "naive\n";
        return naive_solution(x, y, start, end);
    }

    int mid = start + (end - start) / 2;
    //cout << "mid " << mid << "\n";
    double mid_point_x = x[mid];
    // cout << "mid_point_x " << mid_point_x << "\n";

    double d1 = closet(x, y, start, mid);
    //cout << "d1 " << d1 << "\n";
    double d2 = closet(x, y, mid + 1, end);
    // cout << "d2 " << d2 << "\n";

    double d = min(d1, d2);
    //cout << "d " << d << "\n";


    vector<int> x_strip;
    vector<int> y_strip;
    for (int i = 0; i < x.size(); i++)
    {
        if (abs(x[i] - mid_point_x) < d)
        {
            x_strip.push_back(x[i]);
            y_strip.push_back(y[i]);
        }
    }
    //cout << "strip\n";


    return min(d, strip_closest(x_strip, y_strip, d));
}
double minimal_distance(vector<int> x, vector<int> y)
{
    //write your code here
    randomized_quick_sort(x, y, 0, x.size() - 1);


    return closet(x, y, 0, x.size() - 1);

    return 0.;
}
int main()
{
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";

}
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
        }
    }
    swap(a[l], a[j]);
    
    return j;
}
void randomized_quick_sort(vector<int>& a, vector<int>& b, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    int m = partition2(a, b, l, r);

    randomized_quick_sort(a, b, l, m - 1);
    randomized_quick_sort(a, b, m + 1, r);
}
struct point
{
    int x; int y;
};
double min_dist(point p1,point p2)
{
    return  sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
double naive_solution(point p[], int n)
{
    double min = TMP_MAX;
    //cout << "\n naive in\n" << start << "  " << end << " \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (min_dist(p[i], p[j]) < min)
            {
                min = min_dist(p[i],p[j]);

            }
        }
    }
    return min;
}
double strip_closest(point strip[], int n, float d)
{
    double min = d;  
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; j++)
        {
            if (min_dist(strip[i], strip[j]) < min)
                min = min_dist(strip[i], strip[j]);
        }
    }
    return min;
}
double closest(point px[], point py[], int n)
{
    if (n <= 3)
        return naive_solution(px, n);

    int mid = n / 2;
    point midPoint = px[mid];

    point* Pyl = new point[mid];   
    point* Pyr = new point[n - mid];  
    int l = 0, r = 0;  
    for (int i = 0; i < n; i++)
    {
        if ((py[i].x < midPoint.x || (py[i].x == midPoint.x && py[i].y < midPoint.y)) && l < mid)
        {
            Pyl[l] = py[i];
            l++;
        }
        else
        {
            Pyr[r] = py[i];
            r++;
        }
    }

    float dl = closest(px, Pyl, mid);
    float dr = closest(px + mid, Pyr, n - mid);
    float d = min(dl, dr);

    point* strip = new point[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(py[i].x - midPoint.x) < d)
        {
            strip[j] = py[i];
            j++;
        }
           
    }
  
    return strip_closest(strip, j, d);
}
int compareX(const void* a, const void* b)
{
    point* p1 = (point*)a, * p2 = (point*)b;
    return (p1->x != p2->x) ? (p1->x - p2->x) : (p1->y - p2->y);
}
int compareY(const void* a, const void* b)
{
    point* p1 = (point*)a, * p2 = (point*)b;
    return (p1->y != p2->y) ? (p1->y - p2->y) : (p1->x - p2->x);
}
float minimal_distance(point P[], int n)
{
    point* px = new point[n];
    point* py = new point[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = P[i];
        py[i] = P[i];
    }

    qsort(px, n, sizeof(point), compareX);
    qsort(py, n, sizeof(point), compareY);
     
    return closest(px, py, n);
}
int main()
{
    int n;
    cin >> n;
    point* p = new point[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(p,n) << "\n";

}
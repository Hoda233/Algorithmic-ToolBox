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

struct point
{
    int x; 
    int y;
};

double calcdist(point p1, point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double naive_solution(point P[], int n)
{
    double m = TMP_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            m = min(m, calcdist(P[i], P[j]));
        }
    }
    return m;
}

int compare_x(const void* a, const void* b) 
{
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return (p1->x - p2->x);
}

int compare_y(const void* a, const void* b)
{
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return (p1->y - p2->y);
}

double strip_closet(point strip[], int size, double d)
{
    double m = d;
    qsort(strip, size, sizeof(point), compare_y);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < m; j++)
        {
            m = min(m, calcdist(strip[i], strip[j]));
        }
    }  
    return m;
}

double closet(point points[], int n)
{
    if (n <= 3 )
        return naive_solution(points, n);

    int mid = n / 2;
    point midPoint = points[mid];

    double dl = closet(points, mid);
    double dr = closet(points + mid, n - mid);
    double d = min(dl, dr);

    point* strip=new point[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(points[i].x - midPoint.x) < d)
        {
            strip[j] = points[i];
            j++;
        }
    }
    return min(d, strip_closet(strip, j, d)); 
}


double minimal_distance(point points[], int n)
{
    qsort(points, n, sizeof(point), compare_x);
    return closet(points, n);
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
    std::cout << std::setprecision(9) << minimal_distance(p, n) << "\n";
}
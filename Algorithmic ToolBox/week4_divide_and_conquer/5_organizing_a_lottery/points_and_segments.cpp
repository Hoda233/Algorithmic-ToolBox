#include <iostream>
#include <vector>
using namespace std;
using std::vector;


int partition2(vector<int>& a, int l, int r) {
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
void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);

    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    //write your code here
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int binary_search_start(vector<int> starts, int x)
{
    //if found find last occurence , if not find where should it be (after)

    int left = 0, right = starts.size() - 1;
    //write your code here

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (x == starts[mid] && mid == starts.size() - 1)
            return mid;
        else  if (x == starts[mid] && x < starts[mid + 1])
            return mid;
        else  if (x < starts[mid])
            right = mid - 1;
        else
            left = mid + 1;

    }
    return left - 1;
}
int binary_search_end(const vector<int>& a, int x)
{
    //if found find first occurence , if not find where should it be (before)

    int left = 0, right = (int)a.size() - 1;
    //write your code here
    if (x < a[0])
        return 0;
    else if (x > a[a.size() - 1])
        return (a.size());
    else
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (x == a[mid] && mid == 0)
                return mid;
            else  if (x == a[mid] && x > a[mid - 1])
                return mid;
            else  if (x > a[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

vector<int> search(vector<int> starts, vector<int> ends, vector<int> points)
{
    randomized_quick_sort(starts, 0, starts.size() - 1);
    randomized_quick_sort(ends, 0, ends.size() - 1);

    vector<int> results(points.size());
    for (int i = 0; i < points.size(); i++)
    {
        results[i] = 0;
        int s = binary_search_start(starts, points[i]);  //num = s + e - intersection ---> intersection = s + e - num
        int e = binary_search_end(ends, points[i]);
        results[i] = (s + 1) + (ends.size() - e) - ends.size();
    }
    return results;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    //use fast_count_segments
    vector<int> cnt = search(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }


}
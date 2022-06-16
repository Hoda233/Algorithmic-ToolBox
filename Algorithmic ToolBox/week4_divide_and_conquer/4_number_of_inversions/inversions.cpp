#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int>& a, vector<int>& b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1) return number_of_inversions;
    size_t ave = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);
    //write your code here
    return number_of_inversions;
}



int merge(int result[], int a[], int left, int mid, int right) //left is the start of first array
                                                              //mid is the start of the second array
{
    int count = 0;

    int i = left;
    int j = mid;
    int result_index = left;
    while (i <= mid - 1 && j <= right)
    {
        if (a[i] <= a[j])
        {
            result[result_index] = a[i];
            i++;
            result_index++;
        }
        else
        {
            result[result_index] = a[j];
            j++;
            result_index++;
            count += (mid - i);   //  here it is 
        }
    }

    while (i <= mid - 1)
    {
        result[result_index] = a[i];
        i++;
        result_index++;
    }
    while (j <= right)
    {
        result[result_index] = a[j];
        j++;
        result_index++;
    }
    for (int i = left; i <= right; i++)
    {
        a[i] = result[i];
    }
    return count;
}

int mergesort(int result[], int a[], int left, int right)
{
    int count = 0;
    int mid = 0;
    if (left < right)
    {
        mid = (right + left) / 2;
        count = mergesort(result, a, left, mid);
        count += mergesort(result, a, mid + 1, right);
        count += merge(result, a, left, mid + 1, right); //left is the start of first array
                                                         //mid+1 is the start of the second array
    }
    return count;

}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    //vector<int> b(a.size());
    //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
    int* result = new int[n];
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
    std::cout << mergesort(result, arr, 0, n - 1) << '\n';

}

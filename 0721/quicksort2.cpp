#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int right)
{
    int n1 = left + (right - left);
    int n2 = right - left;
}

void mergesort(vector<int>& arr, int left, int mid, int right)
{

}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
}

int main(void)
{
    vector<int> arr = {9, 3, 4, 2, 1, 6, 7, 5, 10, 52};

    quicksort(arr, 0, arr.size() - 1);
    for(int n : arr)
    {
        cout << n << " ";
    }

    return 0;
}
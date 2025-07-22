#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high)
{
    if(low >= high)
    {
        return;
    }

    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left;
}

int main()
{
    vector<int> arr = {64, 34, 25, 90, 12, 22, 11};
  
    int n = arr.size();

    quicksort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
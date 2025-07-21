#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftarr(n1), rightarr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

int main(void)
{
    vector<int> arr = {11, 34, 25, 12, 90, 22, 64};
   
    mergesort(arr, 0, arr.size() - 1);
    for (int n : arr)
    {
        cout << n << " ";
    }

    return 0;
}
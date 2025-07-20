#include <iostream>
#include <vector>

using namespace std;

int magicPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    } 
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivotIndex = magicPartition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, high);
}

void printArray(const vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 2, 8, 9, 1};

    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    printArray(arr);

    return 0;
}
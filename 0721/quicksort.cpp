#include <iostream>
#include <vector>

using namespace std;

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

            for (int n : arr)
            {
                cout << n << " ";
            }
            cout << endl;
        }
    }

    swap(arr[i + 1], arr[high]);
    cout << endl;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        cout << pi << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 90, 12, 22, 11};
    // 64, 34, 25, 12, 22, 90, 11
    // 64, 11, 25, 12, 22, 90, 34
    // 64, 11, 34, 12 ,22, 90, 25
    // 64, 11, 34, 25, 22, 90, 12
    // 64, 11, 34, 25, 22, 90, 12
    //
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
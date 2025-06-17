#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("maxnum.txt", "r", stdin);
    vector<int> arr(9);

    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    auto iter = max_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());

    int dis = distance(arr.begin(), iter);

    cout << max << endl;
    cout << dis + 1 << endl;

    return 0;
}
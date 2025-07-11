#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("expense.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 1;
        int temp = mid;

        for (int i = 0; i < N; i++)
        {
            if (temp < arr[i])
            {
                temp = mid;
                count++;
                temp -= arr[i];
            }
            else
            {
                temp -= arr[i];
            }
        }

        if (count > M)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
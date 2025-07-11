#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("budget.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int totalbudget;
    cin >> totalbudget;

    int left = 1;
    int right = *max_element(arr.begin(), arr.end());
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] > mid)
            {
                sum += mid;
            }
            else
            {
                sum += arr[i];
            }
        }

        if (sum > totalbudget)
        {
            right = mid - 1;
        }
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
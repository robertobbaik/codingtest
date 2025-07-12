#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ryan.txt", "r", stdin);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int ryan_count = 0;
    int min_len = N + 1;

    for (int right = 0; right < N; right++)
    {
        if (arr[right] == 1)
        {
            ryan_count++;
        }

        while (ryan_count >= K)
        {
            min_len = min(min_len, right - left + 1);
            if (arr[left] == 1)
            {
                ryan_count--;
            }
            left++;
        }
    }

    if (min_len == N + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_len << endl;
    }

    return 0;
}
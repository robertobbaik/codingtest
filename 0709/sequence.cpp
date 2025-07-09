#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequence.txt", "r", stdin);

    int N, S;

    cin >> N >> S;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = 0;
    int sum = 0;

    int min_len = N + 1;

    while(right < N)
    {
        sum += arr[right];
        while(sum >= S)
        {
            min_len = min(min_len, right - left + 1);
            sum -= arr[left];

            left++;
        }

        right++;
    }

    if (min_len == N + 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << min_len << endl;
    }

    return 0;
}
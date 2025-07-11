#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<long long> arr;

bool can(long long time)
{
    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        count += time / arr[i];
         if (count >= M) return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("immigration.txt", "r", stdin);

    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long left = 1;
    long long right = (long long)*max_element(arr.begin(), arr.end()) * M;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (can(mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
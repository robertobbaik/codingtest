#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countLessEqual(long long n, long long x)
{
    long long count = 0;
    for (long long i = 1; i <= n; i++)
    {
        count += min(x / i, n);
    }
    return count;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Knum.txt", "r", stdin);

    long long N, K;

    cin >> N >> K;

    long long left = 1, right = N * N;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = countLessEqual(N, mid);

        if (count >= K)
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
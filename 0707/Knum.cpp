#include <iostream>
#include <vector>

using namespace std;

long long countLessEqual(long long mid, int N)
{
    long long count = 0;
    for (int i = 1; i < N + 1; i++)
    {
        count += min((long long)N, mid / i);
    }

    return count; 
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Knum.txt", "r", stdin);

    int N, K;
    cin >> N >> K;

    long long left = 1;
    long long right = K;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = countLessEqual(mid, N);

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
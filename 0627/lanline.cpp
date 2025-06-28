#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lanline.txt", "r", stdin);

    int K, N;
    cin >> K >> N;

    vector<int> lan(K);
    for (int i = 0; i < K; i++)
    {
        cin >> lan[i];
    }

    long long left = 1;
    long long right = *max_element(lan.begin(), lan.end());
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < K; i++)
        {
            count += lan[i] / mid;
        }

        if (count >= N)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequence.txt", "r", stdin);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int left = 0;
    int right = K - 1; 

    while (right < N)
    {
        int currentSum = 0;
        for (int i = left; i <= right; i++)
        {
            currentSum += arr[i];
        }
        maxSum = max(maxSum, currentSum);
        left++;
        right++;
    }

    cout << maxSum << endl;
    return 0;
}
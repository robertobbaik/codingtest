#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("jumong.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int result = 0;
    int left = 0;
    int right = N - 1;

    while(left < right)
    {
        int mid = arr[left] + arr[right];

        if(mid < M)
        {
            left++;
        }
        else if (mid > M)
        {
            right--;
        }
        else
        {
            result++;
            left++;
            right--;
        }
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("threeliquid.txt", "r", stdin);

    int N;
    cin >> N;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long min_sum = LLONG_MAX;
    long long result[3];

    for(int i = 0; i < N - 2; i++)
    {
        int left = i + 1;
        int right = N - 1;

        while(left < right)
        {
            long long sum = arr[i] + arr[left] + arr[right];

            if(abs(sum) < abs(min_sum))
            {
                min_sum = sum;
                result[0] = arr[i];
                result[1] = arr[left];
                result[2] = arr[right];
            }

            if(sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                break;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
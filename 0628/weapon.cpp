#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("weapon.txt", "r", stdin);
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = N - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == N)
        {
            count++;
            left++;
            right--;
        }
        else if (sum < N)
        {
            left++;
        }
        else if (sum > N)
        {
            right--;
        }
    }

    cout << count << endl;
    return 0;
}
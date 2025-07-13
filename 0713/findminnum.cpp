#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("findminnum.txt", "r", stdin);

    int N, L;

    cin >> N >> L;

    vector<int> arr(N);
    vector<int> results;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        int min_num = INT_MAX;
        for(int j = L - 1; j >= 0; j--)
        {
            if(i - j < 0)
            {
                continue;
            }
            else
            {
                min_num = min(min_num, arr[i - j]);
            }
        }

        results.push_back(min_num);
    }

    for(int n : results)
    {
        cout << n << " ";
    }

    return 0;
}
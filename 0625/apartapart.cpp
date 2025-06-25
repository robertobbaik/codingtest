#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("apartapart.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int k, n;
        cin >> k >> n;

        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                dp[j] += dp[j - 1];
            }
        }

        cout << dp[n] << endl;
    }

    return 0;
}
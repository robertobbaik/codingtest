#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	while (T--)
	{
		int k, n;
		cin >> k >> n;

		int dp[15];

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
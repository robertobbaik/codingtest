#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		vector<long long> dp(n + 1);

		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		dp[4] = 7;

		for (int i = 5; i < n + 1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << endl;
	}

	return 0;
}
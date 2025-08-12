#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	int T;
	cin >> T;

	vector<vector<int>> dp(15, vector<int>(15));

	for (int i = 1; i < 15; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	while (T--)
	{
		int k, n;
		cin >> k >>n;

		cout << dp[k][n] << '\n';
	}
	return 0;
}
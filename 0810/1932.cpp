#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> triangle(n);
	vector<vector<int>> dp(n);

	for (int i = 0; i < n; i++)
	{
		triangle[i].resize(i + 1);
		dp[i].resize(i + 1);
		for (int j = 0; j < i + 1; j++)
		{
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> wines(n);

	for (int i = 0; i < n; i++)
	{
		cin >> wines[i];
	}

	vector<int> dp(n);

	dp[0] = wines[0];
	dp[1] = wines[0] + wines[1];

	for (int i = 2; i < n; i++)
	{
		dp[i] = max({dp[i - 1], dp[i - 2] + wines[i], (i >= 3 ? dp[i - 3] : 0) + wines[i - 1] + wines[i]});
	}

	cout << dp[n - 1] << endl;

	return 0;
}
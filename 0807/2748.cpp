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

	vector<long long> dp(n + 1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}
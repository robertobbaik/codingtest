#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<long long> dp(max(N + 1, 5));

	dp[0] = 0;
	dp[1] = 1; // 2
	dp[2] = 2; // 4
	dp[3] = 3; // 8
	dp[4] = 5; // 16

	for (int i = 5; i < N + 1; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] << endl;
	return 0;
}
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

	vector<int> stair(N);

	for (int i = 0; i < N; i++)
	{
		cin >> stair[i];
	}

	vector<int> dp(N + 1);

	dp[1] = stair[0];
	dp[2] = stair[0] + stair[1];
	dp[3] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 4; i < N + 1; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i - 1], dp[i - 3] + stair[i - 2] + stair[i - 1]);
	}

	cout << dp[N] << endl;

	return 0;
}
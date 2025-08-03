#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		vector<long long> dp(max(N + 1, 6));

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;

		for (int i = 6; i < N + 1; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 3];
		}

		cout << dp[N] << endl;
	}
	return 0;
}
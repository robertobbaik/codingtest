#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	while(T--)
	{
		int num;
		cin >> num;

		int zeroCount = 0;
		int oneCount = 0;

		vector<pair<int, int>> dp(num + 1);

		dp[0] = {1, 0};
		if(num >= 1)
		{
			dp[1] = {0, 1};
		}
		
		for(int i = 2; i < num + 1; i++)
		{
			dp[i] = {dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second};
		}

		cout << dp[num].first << " " << dp[num].second << endl;
	}

	return 0;
}
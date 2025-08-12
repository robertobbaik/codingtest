#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> dp(11);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	while(T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
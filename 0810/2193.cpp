#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> dp(max(N + 1, 4));

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;


	for(int i = 4; i < N + 1; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << endl;
	
	return 0;
}
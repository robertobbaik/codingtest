#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long> dp(max(N + 1, 2));

	dp[1] = 9;
	dp[2] = 17;

	for(int i = 3; i < N + 1; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000000;
	}

	cout << dp[N] << endl;

	return 0;
}
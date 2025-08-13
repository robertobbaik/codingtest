#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> dp(N);

	sort(arr.begin(), arr.end());

	dp[0] = arr[0];

	for(int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
		
	}

	cout << accumulate(dp.begin(), dp.end(), 0) << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<long long, long long>> vp;

	for (int i = 0; i < N; i++)
	{
		long long S, B;
		cin >> S >> B;

		vp.push_back(make_pair(S, B));
	}

	int min_gap = INT_MAX;

	for (int mask = 0; mask < (1 << N); mask++)
	{
		int sum_s = 1;
		int sum_b = 0;
		for (int i = 0; i < N; i++)
		{
			if (mask & (1 << i))
			{
				auto [S, B] = vp[i];
				sum_s *= S;
				sum_b += B;
			}
		}
		if (sum_s != 1 && sum_b != 0)
		{

			min_gap = min(min_gap, abs(sum_s - sum_b));
		}
	}

	cout << min_gap << endl;

	return 0;
}
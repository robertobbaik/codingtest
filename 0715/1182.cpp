#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;

	cin >> N >> S;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int count = 0;

	for (int mask = 1; mask < (1 << N); mask++)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (mask & (1 << i))
			{
				sum += arr[i];
			}
		}

		if (sum == S)
		{
			count++;
		}
		
	}

	cout << count << endl;

	return 0;
}
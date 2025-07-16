#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> arr;
int result = 0;
int prev_min_gap = 0;

int solve()
{
	for (int i = 0; i < N; i++)
	{
		int left = i + 1;
		int right = N - 1;

		while (left < right)
		{
			int sum = arr[i] + arr[left] + arr[right];
			int gap = M - sum;
			
			if (gap > 0 && gap < prev_min_gap)
			{
				result = sum;
				prev_min_gap = gap;
			}

			if (sum < M)
			{
				left++;
			}
			else if (sum > M)
			{
				right--;
			}
			else
			{
				return sum;
			}
		}
	}

	return result;
}

int main()
{
	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	prev_min_gap = M;

	sort(arr.begin(), arr.end());
	result = solve();

	cout << result << endl;

	return 0;
}
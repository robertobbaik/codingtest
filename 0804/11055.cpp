#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> dp;

	for(int i = 0; i < N; i++)
	{
		int sum = arr[i];
		for(int j = i; j < N; j++)
		{
			if(i == j) continue;

			if(arr[j] <= arr[j - 1]) break;

			sum += arr[j];
		}

		dp.push_back(sum);
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;


	return 0;
}
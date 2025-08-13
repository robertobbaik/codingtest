#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr1(N);
	vector<int> arr2(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr2[i];
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.rbegin(), arr2.rend());

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += arr1[i] * arr2[i];
	}

	cout << sum << endl;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> arr1(8001, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr1[arr[i] + 4000]++;
	}
	int avg = round((double)accumulate(arr.begin(), arr.end(), 0) / N);
	cout << avg << endl;
	sort(arr.begin(), arr.end());
	cout << arr[N / 2] << endl;

	int temp = *max_element(arr1.begin(), arr1.end());
	vector<int> temp1;

	for (int i = 0; i < 8001; i++)
	{
		if (arr1[i] == temp)
		{
			temp1.push_back(i - 4000);
		}
	}

	if (temp1.size() == 1)
	{
		cout << temp1[0] << endl;
	}
	else
	{
		cout << temp1[1] << endl;
	}

	cout << arr[N - 1] - arr[0] << endl;
	return 0;
}
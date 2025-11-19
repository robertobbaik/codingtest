#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N; 
	cin >> N;

	vector<double> arr(N);
	
	
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	double maxNum = *max_element(arr.begin(), arr.end());

	for(int i = 0; i < N; i++)
	{
		arr[i] = arr[i] / maxNum * 100;
	}

	double acm = accumulate(arr.begin(), arr.end(), 0.0f);
	double answer = acm / N;

	cout << answer << endl;

	return 0;
}
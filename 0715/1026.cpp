#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;

int calc(vector<int> &a, vector<int> &b)
{
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int sum = a[i] * b[i];
		result += sum;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	int min_sum = INT_MAX;
	sort(A.begin(), A.end());

	sort(B.rbegin(), B.rend());

	int sum = calc(A, B);

	cout << sum << endl;

	return 0;
}
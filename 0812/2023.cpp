#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrimeNum(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;

	for (int i = 3; i <= sqrt(num); i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void dfs(int num, int depth, int n)
{
	if(depth == n)
	{
		cout << num << '\n';
		return;
	}

	for(int i = 1; i <= 9; i += 2)
	{
		int newNum = num * 10 + i;
		if(isPrimeNum(newNum))
		{
			dfs(newNum, depth + 1, n);
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> primenums = {2, 3, 5, 7};

	for(int prime : primenums)
	{
		dfs(prime, 1, N);
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrimenum(int num)
{
	if(num < 2) return false;
	if(num == 2) return true;
	if(num % 2 == 0) return false;

	for(int i = 3; i <= sqrt(num); i += 2)
	{
		if(num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	for(int i = M; i <= N; i++)
	{
		if(isPrimenum(i))
		{
			cout << i << "\n";
		}
	}

	return 0;
}
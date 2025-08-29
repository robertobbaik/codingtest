#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int MAX = 246912;

	vector<bool> isPrime(MAX + 1, true);

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		int count = 0;
		if (n > 0)
		{
			for (int i = n + 1; i <= 2 * n; i++)
			{
				if (isPrime[i])
				{
					count++;
				}
			}
		}
		else
		{
			break;
		}
		cout << count << "\n";
	}
	return 0;
}
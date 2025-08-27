
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	while (k > 0)
	{
		if (n > m * 2)
		{
			n--;
		}
		else
		{
			m--;
		}
		k--;
	}

	int teams = min(n / 2, m);

	cout << teams << endl;

	return 0;
}
#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c)
{
	if (b == 0)
	{
		return 1;
	}

	long long half = power(a, b / 2, c);
	half = (half * half) % c;

	if(b % 2 == 1)
	{
		half = (half * a) % c;
	}
	return half;
}

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	cout << power(A, B, C) << endl;
	return 0;
}
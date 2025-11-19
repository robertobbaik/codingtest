#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int c = b % 10;
	int d = b % 100 - c;
	int e = b % 1000 - d - c;

	cout << a * c << endl;
	cout << a * d / 10 << endl;
	cout << a * e / 100 << endl;
	cout << a * b << endl;
	return 0;
}
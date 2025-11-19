#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cin >> A >> B;

	int revA = (A % 10) * 100 + ((A / 10) % 10) * 10 + (A / 100);
	int revB = (B % 10) * 100 + ((B / 10) % 10) * 10 + (B / 100);

	cout << max(revA, revB) << endl;

	return 0;
}
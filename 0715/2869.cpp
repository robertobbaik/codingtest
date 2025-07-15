#include <iostream>
using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	
	if(A >= V)
	{
		cout << 1 << endl;
		return 0;
	}

	int day = (V - B + A - B - 1) / (A - B);


	cout << day << endl;

	return 0;
}
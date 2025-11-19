#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;

	for(int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if(n < X)
		{
			cout << n << " "; 
		}
	}

	return 0;
}
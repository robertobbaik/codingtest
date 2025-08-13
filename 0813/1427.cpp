#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	string str = to_string(N);

	sort(str.rbegin(), str.rend());

	cout << str << endl;

	
	return 0;
}
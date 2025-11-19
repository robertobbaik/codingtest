#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int wordCount = 0;

	string word;

	while (cin >> word)
	{
		wordCount++;
	}

	cout << wordCount << endl;
	return 0;
}
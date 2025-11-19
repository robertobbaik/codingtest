#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string item;

	while (getline(ss, item, delimiter))
	{
		result.push_back(item);
	}

	return result;
}

int sum(string str)
{
	vector<string> numbers = split(str, '+');
	int sum = 0;

	for (string num : numbers)
	{
		sum += stoi(num);
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	vector<string> parts = split(str, '-');

	int result = sum(parts[0]);

	for (int i = 1; i < parts.size(); i++)
	{
		result -= sum(parts[i]);
	}

	cout << result << endl;

	return 0;
}
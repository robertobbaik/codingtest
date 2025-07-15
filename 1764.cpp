#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> m;
	vector<string> temp;

	for (int i = 0; i < N + M; i++)
	{
		string str;
		cin >> str;

		m[str]++;
	}

	for (auto [str, cnt] : m)
	{
		if (m[str] == 2)
		{
			temp.push_back(str);
		}
	}

	cout << temp.size() << '\n';

	for (string str : temp)
	{
		cout << str << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string,int>& a, pair<string, int>& b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main()
{
	int N, M;

	cin >> N >> M;

	string str;
	cin >> str;

	vector<pair<string, int>> arr;

	for (int i = 0; i < N - 1; i++)
	{
		string s;
		cin >> s;

		arr.push_back({s, 0});
	}

	for(int i = 0; i < N - 1; i++)
	{
		int count = 0;
		for(int j = 0; j < M; j++)
		{
			if(str[j] == arr[i].first[j])
			{
				count++;
			}
		}

		arr[i].second = count;
	}

	sort(arr.begin(), arr.end(), compare);

	cout << arr[0].first << endl;
	cout << arr[0].second << endl;

	return 0;
}
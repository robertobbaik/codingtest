#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if(a.first == b.first)
	{
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> vp(N);

	for(int i = 0; i < N; i++)
	{
		int x, y;

		cin >> x >> y;

		vp[i] = make_pair(x, y);
	}

	sort(vp.begin(), vp.end());

	for(auto p : vp)
	{
		cout << p.first << " " << p.second << '\n';
	}

	return 0;
}
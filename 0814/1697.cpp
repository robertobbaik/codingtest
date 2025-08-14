#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> visited(100001, -1);

	queue<int> q;
	q.push(N);
	visited[N] = 0;

	while(!q.empty())
	{
		int pos = q.front();
		q.pop();

		if(pos == K)
		{
			cout << visited[pos] << endl;
			return 0;
		}

		vector<int> next = {pos - 1, pos + 1, pos * 2};

		for(int np : next)
		{
			if(np >= 0 && np <= 100000 && visited[np] == -1)
			{
				visited[np] = visited[pos] + 1;
				q.push(np);
			}
		}
	}

	return 0;
}
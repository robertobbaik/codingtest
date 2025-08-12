#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;

			if (pq.size() < N)
			{
				pq.push(n);
			}
			else if(pq.top() < n)
			{
				pq.pop();
				pq.push(n);
			}
		}
	}

	cout << pq.top() << endl;

	return 0;
}
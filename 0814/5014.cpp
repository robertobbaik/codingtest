#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> q;
	vector<bool> visited(F + 1, false);
	
	q.push({S, 0});
	visited[S] = true;

	while(!q.empty())
	{
		auto[floor, count] = q.front();
		q.pop();

		if(floor == G)
		{
			cout << count << endl;
			return 0;
		}

		if(floor - D >= 1 && !visited[floor - D])
		{
			q.push({floor - D, count + 1});
			visited[floor - D] = true;
		}

		if(floor + U <= F && !visited[floor + U])
		{
			q.push({floor + U, count + 1});
			visited[floor + U] = true;
		}		
	}

	cout << "use the stairs" << endl; 

	return 0;
}
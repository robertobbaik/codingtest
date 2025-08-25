#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int D(int n)
{
	return (n * 2) % 10000;
}

int S(int n)
{
	return n == 0 ? 9999 : n - 1;
}

int L(int n)
{
	return (n % 1000) * 10 + n / 1000;
}

int R(int n)
{
	return (n % 10) * 1000 + n / 10;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int A, B;
		cin >> A >> B;

		bool visited[10000] = {false};

		queue<pair<int, string>> q;

		q.push({A, ""});
		visited[A] = true;
		while (!q.empty())
		{
			auto [num, commands] = q.front();
			q.pop();

			if (num == B)
			{
				cout << commands << endl;
				break;
			}

			int next[4] = {D(num), S(num), L(num), R(num)};
			char ops[4] = {'D', 'S', 'L', 'R'};

			for (int i = 0; i < 4; i++)
			{
				if (!visited[next[i]])
				{
					visited[next[i]] = true;
					q.push({next[i], commands + ops[i]});
				}
			}
		}
	}

	return 0;
}
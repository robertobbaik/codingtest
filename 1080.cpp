#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> matrix;
vector<vector<int>> target;

bool isSame(vector<vector<int>> &matrix2)
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(matrix[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void reverse(vector<vector<int>> &matrix1, pair<int, int> p)
{
	auto [x, y] = p;
	for(int i = x; i < x + 3; i++)
	{
		for(int j = y; j < y + 3; j++)
		{
			matrix1[i][j] += 1;
			matrix1[i][j] %= 2;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	matrix.resize(N, vector<int>(M, 0));
	target.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			target[i][j] = s[j] - '0';
		}
	}

	int count = 0;

	for(int i = 0; i <= N - 3; i++)
	{
		for(int j = 0; j <= M - 3; j++)
		{
			if(matrix[i][j] != target[i][j])
			{
				reverse(matrix, {i, j});
				count++;
			}
		}
	}

	if(isSame(target))
	{
		cout << count << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}
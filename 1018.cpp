#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(const vector<vector<char>> &board, int x, int y, char startColor)
{
	int wrongCount = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char color = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
			if (board[x + i][y + j] != color)
			{
				wrongCount++;
			}
		}
	}
	return wrongCount;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	int startX = N - 7;
	int startY = M - 7;
	int minCount = 64;

	for (int i = 0; i < startX; i++)
	{
		for (int j = 0; j < startY; j++)
		{
			int wcount = check(board, i, j, 'W');
			int bcount = check(board, i, j, 'B');

			minCount = min({wcount, bcount, minCount});
		}
	}

	cout << minCount << endl;
	return 0;
}
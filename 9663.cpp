#include <iostream>
#include <vector>

using namespace std;

int N, total;
vector<vector<bool>> board;

bool isValid(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][col])
		{
			return false;
		}
	}

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}


	for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
	{
		if(board[i][j])
		{
			return false;
		}
	}

	return true;
}

void nqueen(int row)
{
	if (row == N)
	{
		total++;
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if(isValid(row, i))
		{
			board[row][i] = true;
			nqueen(row + 1);
			board[row][i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	board.resize(N, vector<bool>(N, false));

	nqueen(0);
	cout << total << endl;

	return 0;
}
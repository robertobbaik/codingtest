#include <iostream>
#include <vector>

using namespace std;

bool isFinish = false;

bool is_valid(const vector<vector<int>> &board, int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == num)
        {
            return false;
        }

        if (board[i][y] == num)
        {
            return false;
        }

        int temp_y = (x / 3) * 3;
        int temp_x = (y / 3) * 3;
    }
    return true;
}

void backtracking(vector<vector<int>> &board, vector<pair<int, int>> blank, int index)
{
    if (isFinish)
        return;

    if (index == blank.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        return;
    }

    auto [x, y] = blank[index];

    for (int i = 0; i < 9; i++)
    {
        if (is_valid(board, x, y, i + 1))
        {
            board[x][y] = i + 1;
            backtracking(board, blank, index + 1);
            board[x][y] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sudoku.txt", "r", stdin);

    vector<vector<int>> board(9, vector<int>(9, 0));
    vector<pair<int, int>> blank;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                blank.push_back({i, j});
            }
        }
    }

    backtracking(board, blank, 0);

    return 0;
}
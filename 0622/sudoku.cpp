#include <iostream>
#include <vector>

using namespace std;

bool isFinish = false;

bool isValid(const vector<vector<int>> &board, int num, int x, int y)
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

        for(int i = temp_y; i < temp_y + 3; i++)
        {
            for(int j = temp_x; j < temp_x + 3; j++)
            {
                if(board[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void backtracking(vector<vector<int>> &board, vector<pair<int, int>> &blank, int index)
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
        isFinish = true;
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        auto [x, y] = blank[index];

        if (isValid(board, i + 1, x, y))
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
            int num;
            cin >> num;
            board[i][j] = num;

            if (num == 0)
            {
                blank.push_back({i, j});
            }
        }
    }

    backtracking(board, blank, 0);

    return 0;
}
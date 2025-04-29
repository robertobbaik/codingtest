#include <iostream>
#include <vector>

using namespace std;

int N = 9;
vector<vector<int>> board(N, vector<int>(N, 0));
vector<pair<int, int>> blank;
bool isFinish = false;

bool isValid(pair<int, int> p, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (board[p.first][i] == num)
        {
            return false;
        }
        if (board[i][p.second] == num)
        {
            return false;
        }
    }

    int y = (p.first / 3) * 3;
    int x = (p.second / 3) * 3;

    for(int i = y; i < y + 3; i++)
    {
        for(int j = x; j < x + 3; j++)
        {
            if(board[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

void backtracking(int index)
{
    if(isFinish) return;
    if (index == blank.size())
    {
        isFinish = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        
        return;
    }

    for (int i = 0; i < N; i++)
    {
        pair<int, int> p = blank[index];
        if (isValid(p, i + 1))
        {
            board[p.first][p.second] = i + 1;
            backtracking(index + 1);
            board[p.first][p.second] = 0;
        }
    }
}

int main(void)
{
    freopen("sudoku.txt", "r", stdin);
    int N = 9;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                blank.push_back({i, j});
            }
        }
    }

    backtracking(0);

    return 0;
}

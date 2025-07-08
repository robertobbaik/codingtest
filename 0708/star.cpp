#include <iostream>
#include <vector>

using namespace std;

void drawStars(vector<vector<char>> &board, int n, int x, int y)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }

    int size = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            drawStars(board, size, x + i * size, y + j * size);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("star.txt", "r", stdin);

    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N, ' '));
    drawStars(board, N, 0, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
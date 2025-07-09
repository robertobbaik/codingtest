#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int seqeunce = 0;
void quadtree(vector<vector<int>> &board, int startX, int startY, int size)
{
    if (size == 2)
    {
        for (int i = startX; i < startX + 2; i++)
        {
            for (int j = startY; j < startY + 2; j++)
            {
                board[i][j] = seqeunce;
                seqeunce++;
            }
        }
    }
    else
    {
        int half = size / 2;
        quadtree(board, startX, startY, half);
        quadtree(board, startX, startY + half, half);
        quadtree(board, startX + half, startY, half);
        quadtree(board, startX + half, startY + half, half);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Z.txt", "r", stdin);

    int N, r, c;

    cin >> N >> r >> c;

    int size = pow(2, N);

    vector<vector<int>> board(size, vector<int>(size, 0));

    quadtree(board, 0, 0, size);

    cout << board[r][c] << endl;

    return 0;
}
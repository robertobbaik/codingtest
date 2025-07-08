#include <iostream>
#include <vector>

using namespace std;

void quad(const vector<string> &board, int startX, int startY, int size)
{
    char start = board[startX][startY];
    if (size == 1)
    {
        cout << start;
        return;
    }

    bool isSame = true;

    for (int i = startX; i < startX + size; i++)
    {
        for (int j = startY; j < startY + size; j++)
        {
            if (board[i][j] != start)
            {
                isSame = false;
                break;
            }
        }

        if (!isSame)
        {
            break;
        }
    }

    if (isSame)
    {
        cout << start;
    }
    else
    {
        int half = size / 2;
        cout << "(";
        quad(board, startX, startY, half);
        quad(board, startX, startY + half, half);
        quad(board, startX + half, startY, half);
        quad(board, startX + half, startY + half, half);
        cout << ")";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("quadtree.txt", "r", stdin);

    int N;
    cin >> N;

    vector<string> board(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    // cout << "(";
    quad(board, 0, 0, N);
    // cout << ")";
    return 0;
}
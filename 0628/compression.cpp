#include <iostream>
#include <vector>

using namespace std;

int N;
int bluecount = 0;
int whitecount = 0;
vector<vector<int>> board;

void compression(int len, pair<int, int> startPos)
{
    auto [x, y] = startPos;
    int color = board[x][y];

    if (len == 1)
    {
        if (color == 0)
        {
            whitecount++;
        }
        else
        {
            bluecount++;
        }
        return;
    }

    bool isSame = true;

    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (board[i][j] != color)
            {

                isSame = false;
                break;
            }
        }
        if (!isSame)
            break;
    }

    if (isSame)
    {
        if (color == 0)
        {
            whitecount++;
        }
        else
        {
            bluecount++;
        }
    }
    else
    {
        compression(len / 2, make_pair(x, y));
        compression(len / 2, make_pair(x + len / 2, y));
        compression(len / 2, make_pair(x, y + len / 2));
        compression(len / 2, make_pair(x + len / 2, y + len / 2));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("compression.txt", "r", stdin);
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    compression(N, make_pair(0, 0));

    cout << whitecount << "\n"
         << bluecount << endl;

    return 0;
}
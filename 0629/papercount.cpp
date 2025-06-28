#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;

vector<vector<int>> board;
map<int, int> um;

void compression(int len, int x, int y)
{
    int color = board[x][y];

    if (len == 1)
    {
        um[color]++;
        return;
    }

    bool same = true;
    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (board[i][j] != color)
            {
                same = false;
                break;
            }
        }

        if (!same)
            break;
    }

    if (same)
    {
        um[color]++;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int third = len / 3;
                compression(third, x + (i * third), y + (j * third));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("papercount.txt", "r", stdin);
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    compression(N, 0, 0);

    cout << um[-1] << endl;
    cout << um[0] << endl;
    cout << um[1] << endl;

    return 0;
}
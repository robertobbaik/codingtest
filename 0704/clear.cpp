#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> temp;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int r, c, t;
void diffusion(const vector<pair<int, int>> &dust)
{
    for (int i = 0; i < dust.size(); i++)
    {
        auto [x, y] = dust[i];
        int dirCount = 0;
        int diffuseAmount = board[x][y] / 5;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if (board[nx][ny] >= 0)
                {

                    board[nx][ny] += diffuseAmount;
                    dirCount++;
                }
            }
        }

        board[x][y] -= diffuseAmount * dirCount;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("clear.txt", "r", stdin);

    cin >> r >> c >> t;

    board.resize(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    while (t--)
    {
        vector<pair<int, int>> dust;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] > 0)
                {
                    dust.push_back({i, j});
                }
            }
        }

        diffusion(dust);

        cout << "\n";

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
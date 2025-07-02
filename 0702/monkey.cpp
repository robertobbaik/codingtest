#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int jumpX[8] = {-2, 2, -2, 2, -1, 1, -1, 1};
int jumpY[8] = {-1, 1, 1, -1, -2, 2, 2, -2};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("monkey.txt", "r", stdin);

    int K, W, H;
    cin >> K >> W >> H;

    vector<vector<int>> board(H, vector<int>(W, 0));
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(K + 1, false)));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        auto [x, y, jump, count] = q.front();
        q.pop();

        if (x == H - 1 && y == W - 1)
        {
            cout << count << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W)
            {
                if (!visited[nx][ny][jump] && board[nx][ny] == 0)
                {
                    q.push({nx, ny, jump, count + 1});
                    visited[nx][ny][jump] = true;
                }
            }
        }

        if (jump < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + jumpX[i];
                int ny = y + jumpY[i];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W)
                {
                    if (!visited[nx][ny][jump + 1] && board[nx][ny] == 0)
                    {
                        q.push({nx, ny, jump + 1, count + 1});
                        visited[nx][ny][jump + 1] = true;
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
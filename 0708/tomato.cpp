#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tomato.txt", "r", stdin);
    int M, N, H;
    int zero_count = 0;
    int total_tomato = 0;

    cin >> M >> N >> H;
    // cout << M << N << H << endl;
    vector<vector<vector<int>>> board(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<tuple<int, int, int, int>> q;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> board[i][j][k];

                if (board[i][j][k] == 0)
                {
                    total_tomato++;
                }
                else if (board[i][j][k] == 1)
                {
                    total_tomato++;
                    q.push({i, j, k, 0});
                    zero_count++;
                }
            }
        }
    }

    int maxday = 0;

    while (!q.empty())
    {
        auto [z, x, y, day] = q.front();
        q.pop();

        maxday = max(maxday, day);

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H)
            {
                if (board[nz][nx][ny] == 0)
                {
                    board[nz][nx][ny] = 1;
                    zero_count++;
                    q.push({nz, nx, ny, day + 1});
                }
            }
        }
    }

    if (zero_count == total_tomato)
    {
        cout << maxday << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
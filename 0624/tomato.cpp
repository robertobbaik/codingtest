#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tomato.txt", "r", stdin);

    int M, N;

    cin >> M >> N;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<tuple<int, int, int>> q;
    int zeroCount = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push({i, j, 0});
            }
            else if (board[i][j] == 0)
            {
                zeroCount++;
            }
        }
    }

    if (zeroCount == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int result = 0;

    while (!q.empty())
    {
        auto [x, y, t] = q.front();

        result = max(t, result);

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (!visited[nx][ny] && board[nx][ny] == 0)
                {
                    board[nx][ny] = 1;
                    q.push({nx, ny, t + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
            {
                result = -1;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    freopen("destroywall.txt", "r", stdin);
    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = str[j] == '1' ? 1 : 0;
        }
    }

    queue<tuple<int, int, int, int>> q;

    q.push({0, 0, 1, 1});
    visited[0][0][1] = true;

    while (!q.empty())
    {
        auto [x, y, depth, wall] = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << depth << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                // if (!visited[nx][ny][wall])
                // {
                //     if (board[nx][ny] == 1)
                //     {
                //         if (wall == 1)
                //         {
                //             q.push({nx, ny, depth + 1, 0});
                //             visited[nx][ny][wall] = true;
                //         }
                //     }
                //     else
                //     {
                //         q.push({nx, ny, depth + 1, wall});
                //         visited[nx][ny][0] = true;
                //     }
                // }

                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                {
                    if (board[nx][ny] == 0 && !visited[nx][ny][wall])
                    {
                        visited[nx][ny][wall] = true;
                        q.push({nx, ny, depth + 1, wall});
                    }
                    else if (board[nx][ny] == 1 && wall == 1 && !visited[nx][ny][0])
                    {
                        visited[nx][ny][0] = true;
                        q.push({nx, ny, depth + 1, 0});
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
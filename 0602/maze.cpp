#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    freopen("maze.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            maze[i][j] = str[j] == '1' ? 1 : 0;
        }
    }

    q.push({0, 0, 1});

    while (!q.empty())
    {
        auto [x, y, depth] = q.front();

        q.pop();

        if(x == N - 1 && y == M - 1)
        {
            cout << depth << endl;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if(!visited[nx][ny] && maze[nx][ny] == 1)
                {
                    q.push({nx, ny, depth + 1});
                }
            }
        }

    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
int dy[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maze.txt", "r", stdin);
    vector<string> A(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> A[i];
    }

    queue<tuple<int, int, int>> q;
    static bool vis[9][8][8] = {};
    vis[0][7][0] = true;
    q.push({7, 0, 0});

    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop();
        if (x == 0 && y == 7)
        {
            cout << 1;
            return 0;
        }
        if (t >= 8)
        {
            cout << 1;
            return 0;
        }

        for (int i = 0; i < 9; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                continue;

            if (x - t >= 0 && A[x - t][y] == '#')
                continue;
            if (nx - t >= 0 && A[nx - t][ny] == '#')
                continue;
            if (nx - nt >= 0 && A[nx - nt][ny] == '#')
                continue;
            if (vis[nt][nx][ny])
                continue;
            vis[nt][nx][ny] = true;
            q.push({nx, ny, nt});
        }
    }
    cout << 0;
    return 0;
}

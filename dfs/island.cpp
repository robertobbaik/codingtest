// https://www.acmicpc.net/problem/4963
//  대각선으로 인접한 것도 연결조건

#include <vector>
#include <iostream>

using namespace std;

int dx[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

void dfs(const vector<vector<int>> &land, vector<vector<bool>> &visited, int x, int y, int w, int h)
{
    visited[y][x] = true;
    //cout << y << " : " << x << endl;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < w && ny >= 0 && ny < h)
        {
            if (land[ny][nx] == 1 && !visited[ny][nx])
            {
                dfs(land, visited, nx, ny, w, h);
            }
        }
    }
}

void printland(const vector<vector<int>> &land)
{
    for (const auto &v : land)
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    cout << "==============" << endl;
}

int main(void)
{
    //freopen("island.txt", "r", stdin);

    while (true)
    {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        vector<vector<int>> land(h, vector<int>(w, 0));
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int n;
                cin >> n;
                land[i][j] = n;
            }
        }
        int island_count = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (land[i][j] == 1 && !visited[i][j])
                {
                    dfs(land, visited, j, i, w, h);
                    island_count++;
                }
            }
        }

        cout << island_count << endl;
    }

    return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(const vector<vector<int>> &land, vector<vector<bool>> &visited, int x, int y, int N, int rain)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[ny][nx] && land[ny][nx] > rain)
            {
                dfs(land, visited, nx, ny, N, rain);
            }
        }
    }
}

int main(void)
{
    freopen("safearea.txt", "r", stdin);

    int N;
    cin >> N;

    int rain = 8;

    int max_height = 0;

    vector<vector<int>> land(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int safe_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int height;

            cin >> height;

            max_height = max(height, max_height);

            land[i][j] = height;
        }
    }

    for(int rain = 1; rain < max_height; rain++)
    {
        visited.assign(N, vector<bool>(N, false));
        int temp_height = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && land[i][j] > rain)
                {
                    temp_height++;
                    dfs(land, visited, j, i, N, rain);
                }
            }
        }

        safe_count = max(temp_height, safe_count);
    }



    cout << safe_count << endl;

    return 0;
}
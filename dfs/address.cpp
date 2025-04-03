#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<int> temp;
int home_count = 0;

void dfs(const vector<string> &map, vector<vector<bool>> &visited, int x, int y, int N, int idx)
{
    visited[y][x] = true;
    home_count++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[ny][nx] && map[ny][nx] == '1')
            {
                dfs(map, visited, nx, ny, N, idx);
            }
        }
    }
}

int main(void)
{
    freopen("address.txt", "r", stdin);

    int N;

    cin >> N;

    vector<string> map;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        string grid;
        cin >> grid;
        map.push_back(grid);
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j] == '1')
            {
                dfs(map, visited, j, i, N, count);
                count++;
            }

            if(home_count != 0)
            {
                temp.push_back(home_count);
                home_count = 0;
            }
        }
    }

    sort(temp.begin(), temp.end());

    cout << count << endl; 

    for(int n : temp)
    {
        cout << n << endl;
    }

    return 0;
}
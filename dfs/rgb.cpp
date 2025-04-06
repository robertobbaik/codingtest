#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {0, 0, -1, 1};
int dy[8] = {-1, 1, 0, 0};

void dfs(vector<vector<char>> &picture, vector<vector<bool>> &visited, int x, int y, int N, char color)
{
    visited[y][x] = true;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[ny][nx] && picture[ny][nx] == color)
            {
                dfs(picture, visited, nx, ny, N, color);
            }
        }
    }
}

int main(void)
{
    freopen("rgb.txt", "r", stdin);

    int N;

    cin >> N;

    vector<vector<char>> picture(N, vector<char>(N, 'A'));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            picture[i][j] = c;
        }
    }

    vector<char> vc = {'R', 'B', 'G'};
    int count = 0;
    for (int k = 0; k < vc.size(); k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && picture[i][j] == vc[k])
                {
                    dfs(picture, visited, j, i, N, vc[k]);
                    count++;
                }
            }
        }
    }
    //cout << count << endl;

    vc.pop_back();

    for (auto &v : picture)
    {
        for (char &c : v)
        {
            if (c == 'G')
            {
                c = 'R';
            }
        }
    }

    int weak_count = 0;
    visited.assign(N, vector<bool>(N, false));
    for (int k = 0; k < vc.size(); k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && picture[i][j] == vc[k])
                {
                    dfs(picture, visited, j, i, N, vc[k]);
                    weak_count++;
                }
            }
        }
    }

    cout << count << " " << weak_count << endl;

    return 0;
}
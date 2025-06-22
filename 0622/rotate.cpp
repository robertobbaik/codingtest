#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
#include <numeric>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<deque<int>> &circles, vector<vector<bool>> &visited, int x, int y, int N, int M)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (!visited[nx][ny] && circles[nx][ny] != 0)
            {
                if (circles[x][y] == circles[nx][ny])
                {
                    circles[x][y] = 0;
                    circles[nx][ny] = 0;
                }
            }
        }
    }
}

void rotate(deque<int> &dq, int direction, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (direction == 0)
        {
            int n = dq.back();
            dq.pop_back();
            dq.push_front(n);
        }
        else
        {
            int n = dq.front();
            dq.pop_front();
            dq.push_back(n);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("rotate.txt", "r", stdin);

    int N, M, T;

    cin >> N >> M >> T;

    vector<deque<int>> circle(N, deque<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> circle[i][j];
        }
    }

    for (int i = 0; i < T; i++)
    {
        int x, d, k;
        cin >> x >> d >> k;

        for (int j = 0; j < N; j++)
        {
            if ((j + 1) % x == 0)
            {
                rotate(circle[j], d, k);
            }
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && circle[i][j] != 0)
            {
                dfs(circle, visited, i, j, N, M);
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
       int temp = accumulate(circle[i].begin(), circle[i].end(), 0);
       sum += temp;
    }

    cout << sum << endl;

    return 0;
}
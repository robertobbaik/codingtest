#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> board;
vector<vector<int>> temp;

void virus()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp[i][j] = board[i][j];
            if (temp[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (temp[nx][ny] == 0)
                {
                    temp[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int getsafe()
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("virus.txt", "r", stdin);

    cin >> N >> M;

    board.resize(N, vector<int>(M, 0));
    temp.resize(N, vector<int>(M, 0));

    vector<pair<int, int>> empty;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                empty.push_back({i, j});
            }
        }
    }

    int max_safe = 0;

    for (int i = 0; i < empty.size(); i++)
    {
        for (int j = i + 1; j < empty.size(); j++)
        {
            for (int k = j + 1; k < empty.size(); k++)
            {
                board[empty[i].first][empty[i].second] = 1;
                board[empty[j].first][empty[j].second] = 1;
                board[empty[k].first][empty[k].second] = 1;

                virus();

                max_safe = max(max_safe, getsafe());

                board[empty[i].first][empty[i].second] = 0;
                board[empty[j].first][empty[j].second] = 0;
                board[empty[k].first][empty[k].second] = 0;
            }
        }
    }

    cout << max_safe << endl;

    return 0;
}
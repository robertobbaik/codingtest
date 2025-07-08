#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> startPos;
pair<int, int> endPos;

int N, M;

int bfs(const vector<vector<char>> &board, int startX, int startY)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<tuple<int, int, int, unordered_set<char>>> q;
    q.push({startX, startY, 0, {}});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        auto [x, y, t, inventory] = q.front();

        q.pop();

        if (x == endPos.first && y == endPos.second)
        {
            return t;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny])
            {
                char c = board[nx][ny];

                if (isdigit(c))
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, t + 1, inventory});
                }
                else
                {
                    if (c == '.')
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny, t + 1, inventory});
                    }
                    else if (!isupper(c))
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny, t + 1, inventory});
                        inventory.insert(c);
                        visited.resize(N, vector<bool>(M, false));
                    }
                    else if (isupper(c))
                    {
                        if (inventory.count(tolower(c)))
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny, t + 1, inventory});
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maze.txt", "r", stdin);

    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M, ' '));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '0')
            {
                startPos = {i, j};
            }
            else if (board[i][j] == '1')
            {
                endPos = {i, j};
            }
        }
    }

    cout << bfs(board, startPos.first, startPos.second) << endl;

    return 0;
}
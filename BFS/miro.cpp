#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    int distance;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    freopen("miro.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = temp[j] - '0';
        }
    }

    queue<Node> q;
    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        Node current = q.front();
        int x = current.x;
        int y = current.y;

        q.pop();

        if (x == M - 1 && y == N - 1)
        {
            cout << current.distance << endl;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                if (board[ny][nx] == 1 && !visited[ny][nx])
                {
                    // cout << nx << ", " << ny << endl;
                    visited[ny][nx] = true;
                    q.push({nx, ny, current.distance + 1});
                }
            }
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    int depth;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int rx[4] = {-1, 1, -1, 1};
int ry[4] = {1, -1, -1, 1};

pair<int, int> rotate(pair<int, int> p, pair<int, int> pivot, bool left_direction)
{
    int dx = p.first - pivot.first;
    int dy = p.second - pivot.second;

    int rx, ry;

    if (left_direction)
    {
        rx = -dy;
        ry = dx;
    }
    else
    {
        rx = dy;
        ry = -dx;
    }

    return {pivot.first + rx, pivot.second + ry};
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int N = board.size();
    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.push({{0, 0}, {0, 1}});
    vector<vector<bool>> visited1(N, vector<bool>(N, false));
    vector<vector<bool>> visited2(N, vector<bool>(N, false));
    while (!q.empty())
    {
        pair<pair<int, int>, pair<int, int>> pq = q.front();
        visited1[pq.first.first][pq.first.second] = true;
        visited2[pq.second.first][pq.second.second] = true;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int fy = pq.first.first + dy[i];
            int fx = pq.first.second + dx[i];
            int sy = pq.second.first + dy[i];
            int sx = pq.second.second + dx[i];

            if (fy >= 0 && fy < N && fx >= 0 && fx < N && sy >= 0 && sy < N && sx >= 0 && sx < N)
            {
                if (board[fy][fx] == 0 && board[sy][sx] == 0)
                {
                    if (!visited1[fy][fx] || !visited2[sy][sx])
                    {
                        cout << fy << ", " << fx << " ";
                        cout << sy << ", " << sx << endl;

                        q.push({{fy, fx}, {sy, sx}});
                    }
                }
            }
            else
            {
            }
        }

        cout << endl;
    }

    return answer;
}

int solution2(vector<vector<int>> board)
{
    int answer = 0;
    int N = board.size();
    queue<Node> q;

    Node node;
    node.depth = 0;
    node.x = 0;
    node.y = 0;

    q.push(node);

    vector<vector<bool>> visited(N, vector<bool>(N, false));

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        visited[node.y][node.x] = true;

        if (node.x == N - 1 && node.y == N - 1)
        {
            cout << node.depth << endl;
            answer = node.depth;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (!visited[ny][nx])
                {
                    Node next_node;
                    next_node.x = nx;
                    next_node.y = ny;
                    next_node.depth = node.depth + 1;

                    q.push(next_node);
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    int result = solution2(board);
    return 0;
}

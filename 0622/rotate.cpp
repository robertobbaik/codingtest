#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <numeric>

using namespace std;

int dx[4] = {-1, 1, 0, 0}; // 상하
int dy[4] = {0, 0, -1, 1}; // 좌우 (원형 연결)

// 회전 함수
void rotate(deque<int> &dq, int dir, int k)
{
    k %= dq.size();
    if (dir == 0)
    {
        for (int i = 0; i < k; ++i)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
}

// 인접한 숫자 제거
bool eraseAdjacent(vector<deque<int>> &board, int N, int M)
{
    bool erased = false;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < M; ++y)
        {
            if (board[x][y] == 0 || visited[x][y])
                continue;

            int val = board[x][y];
            queue<pair<int, int>> q;
            vector<pair<int, int>> group = {{x, y}};
            visited[x][y] = true;
            q.push({x, y});

            while (!q.empty())
            {
                auto [cx, cy] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int nx = cx + dx[d];
                    int ny = (cy + dy[d] + M) % M;

                    if (nx < 0 || nx >= N)
                        continue;
                    if (visited[nx][ny])
                        continue;
                    if (board[nx][ny] != val)
                        continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    group.push_back({nx, ny});
                }
            }

            if (group.size() > 1)
            {
                for (auto [gx, gy] : group)
                    board[gx][gy] = 0;
                erased = true;
            }
        }
    }

    return erased;
}

// 평균 조정
void adjustAverage(vector<deque<int>> &board, int N, int M)
{
    int sum = 0, count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
            {
                sum += board[i][j];
                count++;
            }

    if (count == 0)
        return;

    double avg = (double)sum / count;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
            {
                if (board[i][j] > avg)
                    board[i][j]--;
                else if (board[i][j] < avg)
                    board[i][j]++;
            }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;

    vector<deque<int>> board(N, deque<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    while (T--)
    {
        int x, d, k;
        cin >> x >> d >> k;

        for (int i = 0; i < N; ++i)
            if ((i + 1) % x == 0)
                rotate(board[i], d, k);

        if (!eraseAdjacent(board, N, M))
            adjustAverage(board, N, M);
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
        result += accumulate(board[i].begin(), board[i].end(), 0);

    cout << result << '\n';
    return 0;
}

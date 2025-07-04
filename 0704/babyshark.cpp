#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N;
vector<vector<int>> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    board.resize(N, vector<int>(N));

    int sharkX = 0, sharkY = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                sharkX = i;
                sharkY = j;
                board[i][j] = 0;
            }
        }
    }

    int sharkSize = 2;
    int eatCount = 0;
    int totalTime = 0;

    while (true)
    {
        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pair<int, int>> q;

        q.push({sharkX, sharkY});
        dist[sharkX][sharkY] = 0;

        vector<pair<int, pair<int, int>>> fishList; // {거리, {x, y}}

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1)
                {
                    if (board[nx][ny] <= sharkSize)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});

                        // 먹을 수 있는 물고기 발견
                        if (board[nx][ny] > 0 && board[nx][ny] < sharkSize)
                        {
                            fishList.push_back({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }

        if (fishList.empty())
            break; // 먹을 수 있는 물고기 없음

        // 가장 가까운 물고기 중 위쪽, 왼쪽 우선으로 정렬
        sort(fishList.begin(), fishList.end(), [](const auto &a, const auto &b)
             {
            if (a.first != b.first) return a.first < b.first;
            if (a.second.first != b.second.first) return a.second.first < b.second.first;
            return a.second.second < b.second.second; });

        // 물고기 먹기
        int fishX = fishList[0].second.first;
        int fishY = fishList[0].second.second;
        int moveTime = fishList[0].first;

        totalTime += moveTime;
        board[fishX][fishY] = 0;
        eatCount++;

        // 크기 증가 확인
        if (eatCount == sharkSize)
        {
            sharkSize++;
            eatCount = 0;
        }

        // 상어 위치 이동
        sharkX = fishX;
        sharkY = fishY;
    }

    cout << totalTime << endl;
    return 0;
}
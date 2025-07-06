#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("babyshark.txt", "r", stdin);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    int startX = 0;
    int startY = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                startX = i;
                startY = j;
                board[i][j] = 0;
            }
        }
    }

    int size = 2;
    int eatCount = 0;
    int totalTime = 0;

    while (true)
    {
        queue<tuple<int, int, int>> q;
        vector<tuple<int, int, int>> fishlist;

        vector<vector<int>> distance(N, vector<int>(N, -1));
        q.push({0, startX, startY});

        while (!q.empty())
        {
            auto [dis, x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (distance[nx][ny] == -1 && board[nx][ny] <= size)
                    {
                        distance[nx][ny] = dis + 1;
                        q.push({dis + 1, nx, ny});

                        if (board[nx][ny] > 0 && board[nx][ny] < size)
                        {
                            fishlist.push_back({dis + 1, nx, ny});
                        }
                    }
                }
            }
        }

        if (fishlist.size() == 0)
            break;

        sort(fishlist.begin(), fishlist.end(), [](const auto &a, const auto &b)
             {
            if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b); });


        int fishX = get<1>(fishlist[0]);
        int fishY = get<2>(fishlist[0]);
        int moveTime = get<0>(fishlist[0]);

        totalTime += moveTime;
        board[fishX][fishY] = 0;
        eatCount ++;

        if(eatCount == size)
        {
            size++;
            eatCount = 0;
        }

        startX = fishX;
        startY = fishY;
    }

    cout << totalTime << endl;

    return 0;
}
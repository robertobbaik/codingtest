#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int limitx = maps[0].size();
    int limity = maps.size();
    vector<vector<bool>> visited(limity, vector<bool>(limitx, false));
    queue<vector<int>> vq;

    vq.push({0, 0, 1});
    visited[0][0] = true;
    while (!vq.empty())
    {
        int x = vq.front()[1];
        int y = vq.front()[0];
        int count = vq.front()[2];

        if (x == limitx -1  && y == limity - 1)
        {
            return count;
        }

        vq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < limitx && ny >= 0 && ny < limity)
            {
                if (maps[ny][nx] == 1 && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    vq.push({ny, nx, count + 1});
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> maps =
        {
            {1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 1},
            {0, 0, 0, 0, 1}
        };
    int result = solution(maps);

    cout << result << endl;
    return 0;
}
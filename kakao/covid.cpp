#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isclosed(pair<int, int> start, pair<int, int> end)
{
    auto [sx, sy] = start;
    auto [ex, ey] = end;

    int distance = abs(sx - ex) + abs(sy - ey);

    return distance <= 2;
}

void dfs(const vector<string> &place, vector<vector<bool>> &visited, pair<int, int> start, int x, int y, int N)
{
    visited[y][x] = true;
    pair<int, int> current = {x, y};
    if (start == current)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (isclosed(start, {nx, ny}) && !visited[ny][nx])
                {
                    dfs(place, visited, start, nx, ny, N);
                }
            }
        }
    }
    else
    {
        if (place[y][x] == 'O')
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (isclosed(start, {nx, ny}) && !visited[ny][nx])
                    {
                        dfs(place, visited, start, nx, ny, N);
                    }
                }
            }
        }
    }
}

int searchmodule(const vector<string> &place, int N)
{
    int p_count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(place[i][j] == 'P')
            {
                p_count++;
            }
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int safe = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (place[i][j] == 'P' && !visited[i][j])
            {
                pair<int, int> start = {j, i};
                safe++;
                dfs(place, visited, start, j, i, N);
            }
        }
    }

    safe = safe == p_count ? 1 : 0;
    //cout << safe << endl;
    return safe;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    int N = places.size();
    for(int i = 0; i < N; i++)
    {
        answer.push_back(searchmodule(places[i], N));
    }
    return answer;
}

int main(void)
{
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    vector<int> answer = solution(places);

    for(int n : answer)
    {
        cout << n << endl;
    }

    return 0;
}

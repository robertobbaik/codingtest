#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("escape.txt", "r", stdin);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    vector<vector<bool>> visited(w + 1, vector<bool>(h + 1, false));

    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    visited[x][y] = true;

    while(!q.empty())
    {
        auto[cx, cy, t] = q.front();
        q.pop();
        
        if(cx == 0 || cx == w || cy == 0 || cy == h)
        {
            cout << t << endl;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(!visited[nx][ny])
            {
                if(nx >= 0 && nx <= w && ny >= 0 && ny <= h)
                {
                    q.push({nx, ny, t + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    return 0;
}
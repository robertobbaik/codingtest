#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_connected(vector<int> &comb)
{
    vector<pair<int, int>> connection;
    vector<vector<bool>> visited(5, vector<bool>(5, false));

    for (int n : comb)
    {
        int x = n / 5;
        int y = n % 5;

        connection.push_back({x, y});
    }

    queue<pair<int, int>> q;

    q.push(connection[0]);
    visited[connection[0].first][connection[0].second] = true;
    int count = 1;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            {
                if (!visited[nx][ny] && find(connection.begin(), connection.end(), make_pair(nx, ny)) != connection.end())
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    count++;
                }
            }
        }
    }

    return count == 7;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bully.txt", "r", stdin);

    vector<string> board(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }

    vector<int> temp(25, 0);

    fill(temp.begin(), temp.begin() + 7, 1);

    do
    {
        vector<int> comb;
        int s_count = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == 1)
            {
                comb.push_back(i);
                int x = i / 5;
                int y = i % 5;
                if (board[x][y] == 'S')
                {
                    s_count++;
                }
            }
        }

        if (s_count >= 4 && is_connected(comb))
        {
            answer++;
        }

    } while (prev_permutation(temp.begin(), temp.end()));

    cout << answer << endl;
    return 0;
}
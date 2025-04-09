#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, vector<pair<int, int>> &vp, pair<int, int> next, pair<int, int> base, int N, int target)
{
    int x = next.first;
    int y = next.second;
    vp.push_back({x - base.first, y - base.second});
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[ny][nx] && board[ny][nx] == target)
            {

                dfs(board, visited, vp, {nx, ny}, base, N, target);
            }
        }
    }
}

vector<pair<int, int>> rotate(const vector<pair<int, int>> &block)
{
    vector<pair<int, int>> result;

    for (const auto &[x, y] : block)
    {
        result.push_back({y, -x});
    }

    int minX = INT_MAX;
    int minY = INT_MAX;

    for (auto &[x, y] : result)
    {
        minX = min(minX, x);
        minY = min(minY, y);
    }

    for (auto &[x, y] : result)
    {
        x -= minX;
        y -= minY;
    }

    sort(result.begin(), result.end());

    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = -1;
    int count = 0;
    int N = game_board.size();

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && game_board[i][j] == 0)
            {
                vector<pair<int, int>> vp;
                dfs(game_board, visited, vp, {j, i}, {j, i}, N, 0);
                temp.push_back(vp);
            }
        }
    }

    vector<vector<pair<int, int>>> temp2;
    visited.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && table[i][j] == 1)
            {
                vector<pair<int, int>> vp;
                dfs(table, visited, vp, {j, i}, {j, i}, N, 1);
                temp2.push_back(vp);
            }
        }
    }

    cout << "Hole" << endl;
    for (const auto &v : temp)
    {
        for (pair<int, int> p : v)
        {
            cout << "{" << p.first << ", " << p.second << "} ";
        }
        cout << endl;
    }

    cout << "---------------------" << endl;

    cout << "Block" << endl;
    for (const auto &v : temp2)
    {
        for (pair<int, int> p : v)
        {
            cout << "{" << p.first << ", " << p.second << "} ";
        }
        cout << endl;
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> game_board = {
        {1, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 0}};

    vector<vector<int>> table = {
        {1, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}};

    int result = solution(game_board, table);

    cout << "--------test---------" << endl;

    vector<pair<int, int>> test = {{0, 0}, {0, 1}, {0, 2}, {-1, 1}};

    for (int i = 0; i < 4; i++)
    {
        test = rotate(test);
        for (const auto &[x, y] : test)
        {
            cout << "{" << x << ", " << y << "}" << " ";
        }
        cout << endl;
    }

    cout << "--------test2---------" << endl;

    vector<pair<int, int>> test2 = {{0, 0}, {0, 1}, {-1, 1}, {1, 1}};

    for (int i = 0; i < 4; i++)
    {
        test2 = rotate(test2);
        for (const auto &[x, y] : test2)
        {
            cout << "{" << x << ", " << y << "}" << " ";
        }
        cout << endl;
    }

    //

    return 0;
}
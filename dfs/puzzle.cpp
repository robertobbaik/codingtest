#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_match(const vector<pair<int, int>> &a, const vector<pair<int, int>> &b)
{
    if (a.size() != b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}

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

vector<pair<int, int>> normalize(const vector<pair<int, int>> &block)
{
    vector<pair<int, int>> result = block;

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

vector<pair<int, int>> rotate(const vector<pair<int, int>> &block)
{
    vector<pair<int, int>> result;

    for (const auto &[x, y] : block)
    {
        result.push_back({y, -x});
    }

    result = normalize(result);

    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;
    int count = 0;
    int N = game_board.size();

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> blanks;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && game_board[i][j] == 0)
            {
                vector<pair<int, int>> vp;
                dfs(game_board, visited, vp, {j, i}, {j, i}, N, 0);
                blanks.push_back(normalize(vp));
            }
        }
    }

    vector<vector<pair<int, int>>> pieces;
    visited.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && table[i][j] == 1)
            {
                vector<pair<int, int>> vp;
                dfs(table, visited, vp, {j, i}, {j, i}, N, 1);
                pieces.push_back(vp);
            }
        }
    }

    vector<bool> piece_used(pieces.size(), false);

    for (auto &blank : blanks)
    {
        for (int j = 0; j < pieces.size(); j++)
        {
            if (piece_used[j] || blank.size() != pieces[j].size())
                continue;

            vector<pair<int, int>> rotated = normalize(pieces[j]);
            bool matched = false;

            for (int r = 0; r < 4; r++)
            {
                if (is_match(blank, rotated))
                {
                    answer += rotated.size();
                    piece_used[j] = true;
                    matched = true;
                    break;
                }
                rotated = rotate(rotated);
            }

            if (matched)
                break;
        }
    }

    cout << answer << endl;

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

    return 0;
}
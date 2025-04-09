#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited,
         vector<pair<int, int>> &shape, int x, int y, int baseX, int baseY,
         int N, int target) {
    visited[y][x] = true;
    shape.push_back({x - baseX, y - baseY});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (!visited[ny][nx] && board[ny][nx] == target) {
                dfs(board, visited, shape, nx, ny, baseX, baseY, N, target);
            }
        }
    }
}

vector<pair<int, int>> rotate(const vector<pair<int, int>> &block) {
    vector<pair<int, int>> result;
    for (const auto &[x, y] : block) {
        result.push_back({y, -x});
    }

    // 정규화
    int minX = INT_MAX, minY = INT_MAX;
    for (auto &[x, y] : result) {
        minX = min(minX, x);
        minY = min(minY, y);
    }
    for (auto &[x, y] : result) {
        x -= minX;
        y -= minY;
    }

    sort(result.begin(), result.end());
    return result;
}

bool isMatch(const vector<pair<int, int>> &a, const vector<pair<int, int>> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int N = game_board.size();
    int answer = 0;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> holes;

    // game_board에서 0(빈 공간) 탐색
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x] && game_board[y][x] == 0) {
                vector<pair<int, int>> shape;
                dfs(game_board, visited, shape, x, y, x, y, N, 0);
                sort(shape.begin(), shape.end());
                holes.push_back(shape);
            }
        }
    }

    // table에서 1(퍼즐 블록) 탐색
    visited.assign(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> blocks;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x] && table[y][x] == 1) {
                vector<pair<int, int>> shape;
                dfs(table, visited, shape, x, y, x, y, N, 1);
                sort(shape.begin(), shape.end());
                blocks.push_back(shape);
            }
        }
    }

    // 블록을 회전시키면서 매칭
    vector<bool> used(blocks.size(), false);

    for (auto &hole : holes) {
        bool matched = false;
        for (int i = 0; i < blocks.size(); i++) {
            if (used[i]) continue;

            vector<pair<int, int>> b = blocks[i];
            for (int r = 0; r < 4; r++) {
                if (isMatch(hole, b)) {
                    answer += b.size();
                    used[i] = true;
                    matched = true;
                    break;
                }
                b = rotate(b);
            }
            if (matched) break;
        }
    }

    return answer;
}

int main(void) {
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

    cout << "답: " << solution(game_board, table) << endl;
    return 0;
}

#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int solution(string dirs)
{
    int answer = 0;
    int x = 5;
    int y = 5;
    unordered_map<char, pair<int, int>> dir;
    map<pair<pair<int, int>, pair<int, int>>, bool> m;

    dir['U'] = {0, 1};
    dir['D'] = {0, -1};
    dir['L'] = {-1, 0};
    dir['R'] = {1, 0};

    for (char d : dirs)
    {
        auto [dx, dy] = dir[d];
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx > 10 || ny < 0 || ny > 10)
            continue;

        if (!m[{{x, y}, {nx, ny}}])
        {
            answer++;
            m[{{x, y}, {nx, ny}}] = true;
            m[{{nx, ny}, {x, y}}] = true;
        }

        x = nx;
        y = ny;
    }

    return answer;
}

int main()
{
    string dirs = "ULURRDLLU";
    cout << solution(dirs) << endl; // ✅ 정답: 7
    return 0;
}
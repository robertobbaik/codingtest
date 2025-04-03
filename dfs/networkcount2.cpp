// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(const vector<vector<int>>& computers, vector<vector<bool>>& visited, int x, int y, int n)
{
    visited[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if(!visited[ny][nx] && computers[ny][nx] == 1)
            {
                dfs(computers, visited, nx, ny, n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && computers[i][j] == 1)
            {
                dfs(computers, visited, j, i, n);
                answer++;
            }
        }
    }

    return answer;
}

int main(void)
{
    int n = 3;

    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}};

    int result = solution(n, computers);

    cout << result << endl;

    return 0;
}
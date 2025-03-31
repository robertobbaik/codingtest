// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, const vector<vector<int>> &computers, vector<bool> &visited, int start)
{
    visited[start] = true;
    for (int i = start; i < n; i++)
    {
        if (computers[start][i] == 1 && !visited[i])
        {
            visited[i] = true;
            dfs(n, computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(n, computers, visited, i);
            answer++;
        }
    }
    return answer;
}

int main(void)
{
    cout << "Hello Network Count" << endl;

    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int answer = solution(3, computers);
    cout << answer << endl;

    return 0;
}
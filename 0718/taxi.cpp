#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<vector<int>> distance(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        distance[i][i] = 0;
    }

    for (auto &fare : fares)
    {
        int u = fare[0], v = fare[1], w = fare[2];
        distance[u][v] = w;
        distance[v][u] = w;
    }

    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (distance[i][k] != INF && distance[k][j] != INF)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    int answer = INF;

    for (int mid = 1; mid < n + 1; mid++)
    {
        if (distance[s][mid] != INF && distance[mid][a] != INF && distance[mid][b] != INF)
        {
            int totalCost = distance[s][mid] + distance[mid][a] + distance[mid][b];
            answer = min(answer, totalCost);
        }
    }

    return answer;
}

int main(void)
{
    int result = solution(6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}});

    cout << result << endl;
    return 0;
}
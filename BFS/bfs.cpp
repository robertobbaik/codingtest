#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<pair<int, int>> graph, int start)
{
    vector<int> answer;
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    q.push(start);

    while(!q.empty())
    {
        
    }
    return answer;
}

int main(void)
{
    vector<pair<int, int>> graph = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {3, 7},
        {4, 8},
        {5, 8},
        {6, 9},
        {7, 9}
    };

    vector<int> result = solution(graph, 1);

    for (int n : result)
    {
        cout << n << " ";
    }

    return 0;
}
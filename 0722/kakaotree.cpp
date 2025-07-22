//https://school.programmers.co.kr/learn/courses/30/lessons/72416
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(vector<int> sales, vector<vector<int>> links)
{
    int answer = 0;
    int n = sales.size();
    vector<vector<int>> graph(n + 1);
    vector<int> teamList;
    vector<bool> teamLeader(n + 1);
    

    for(int i = 0; i < links.size(); i++)
    {
        int a = links[i][0];
        int b = links[i][1];

        teamLeader[a] = true;
        graph[a].push_back(b);
    }

    for(int i = 1; i < n + 1; i++)
    {
        if(teamLeader[i])
        {
            for(int n : graph[i])
            {
                if(teamLeader[n])
                {
                    
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};

    int result = solution(sales, links);

    return 0;
}
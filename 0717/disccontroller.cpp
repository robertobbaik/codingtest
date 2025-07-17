#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());

    int currentTime = 0;
    int jobIndex = 0;
    int totalResponseTime = 0;
    int completedJobs = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    while (completedJobs < jobs.size())
    {
        while (jobIndex < jobs.size() && jobs[jobIndex][0] <= currentTime)
        {
            pq.push({jobs[jobIndex][0], jobs[jobIndex][1]});
            jobIndex++;
        }

        if (!pq.empty())
        {
            auto [requestTime, duration] = pq.top();
            pq.pop();

            currentTime += duration;
            totalResponseTime += (currentTime - requestTime);
            completedJobs++;
        }
        else
        {
            if (jobIndex < jobs.size())
            {
                currentTime = jobs[jobIndex][0];
            }
        }
    }

    return totalResponseTime / jobs.size();
}

int main(void)
{
    int result = solution({{0, 3}, {1, 9}, {3, 5}});

    cout << result << endl;

    return 0;
}
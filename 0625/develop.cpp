#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        q.push(progresses[i]);
    }

    int day = 1;
    int index = 0;
    while (!q.empty())
    {
        int complete = 0;
        int n = q.front();
        while(n + (day * speeds[index]) >= 100 && !q.empty())
        {
            complete++;
            index++;
            q.pop();
            n = q.front();
        }
        if(complete > 0)
        {
            answer.push_back(complete);
        }
        day++;
    }

    return answer;
}

int main(void)
{
    vector<int> result = solution({93, 30, 55}, {1, 30, 5});

    for(int n : result)
    {
        cout << n << endl;
    }

    return 0;
}
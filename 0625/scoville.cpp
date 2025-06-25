#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    if (pq.top() == 0)
    {
        return -1;
    }

    while (pq.size() > 1 && pq.top() < K)
    {
        answer++;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int n = a + (b * 2);

        pq.push(n);
    }

    if (pq.top() >= K)
        return answer;
    else
        return -1;
}

int main(void)
{
    vector<int> scoville = {1, 2, 3, 9, 10, 12};

    int result = solution(scoville, 7);

    cout << result << endl;
    return 0;
}
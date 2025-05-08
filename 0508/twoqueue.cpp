#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -2;
    int sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    int sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    queue<int> q1, q2;
    for (int n : queue1)
    {
        q1.push(n);
    }

    for (int n : queue2)
    {
        q2.push(n);
    }

    if((sum1 + sum2) % 2 != 0)
    {
        return -1;
    }

    int total = (sum1 + sum2) / 2;


    int count = 0;
    int limit = queue1.size() * 3;
    while (sum1 != sum2)
    {
        count++;
        if (limit < count)
        {
            return -1;
        }

        if (sum1 > sum2)
        {
            int n = q1.front();
            q1.pop();
            q2.push(n);
            sum1 -= n;
            sum2 += n;
        }
        else
        {
            int n = q2.front();
            q2.pop();
            q1.push(n);
            sum2 -= n;
            sum1 += n;
        }
    }

    answer = count;
    return answer;
}

int main(void)
{
    vector<int> queue1 = {3, 2, 7, 2};
    vector<int> queue2 = {4, 6, 5, 1};

    int result = solution(queue1, queue2);
    cout << result << endl;
    return 0;
}
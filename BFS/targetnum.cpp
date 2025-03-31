#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int solution(int target, vector<int> numbers)
{
    int answer = 0;
    queue<pair<int, int>> q;

    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> front = q.front();

        q.pop();
        if (front.second >= numbers.size())
        {
            if (front.first == target)
            {
                answer++;
            }
        }
        else
        {
            int num = numbers[front.second];
           
            q.push({front.first + num, front.second + 1});
            q.push({front.first - num, front.second + 1});
        }
    }

    return answer;
}

int main(void)
{
    int result = solution(3, {1, 1, 1, 1, 1});

    cout << result << endl;

    return 0;
}
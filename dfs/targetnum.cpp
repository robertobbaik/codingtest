#include <queue>
#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<int> &numbers, int sum, int depth, int &answer, int target)
{
    if (depth >= numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }
    else
    {
        dfs(numbers, sum + numbers[depth], depth + 1, answer, target);
        dfs(numbers, sum - numbers[depth], depth + 1, answer, target);
    }
}

int solution(int target, vector<int> numbers)
{
    int answer = 0;

    dfs(numbers, 0, 0, answer, target);

    return answer;
}

int main(void)
{
    int result = solution(4, {4, 1, 2, 1});

    cout << result << endl;

    return 0;
}
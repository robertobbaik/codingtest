#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int aux, vector<vector<int>> &result)
{
    if (n == 1)
    {
        result.push_back({from, to});
        return;
    }

    hanoi(n - 1, from, aux, to, result);
    result.push_back({from, to});
    hanoi(n - 1, aux, to, from, result);
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    hanoi(n, 1, 3, 2, answer);

    return answer;
}
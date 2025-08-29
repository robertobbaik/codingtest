#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    vector<int> answer(n);

    int base = s / n;
    int remainder = s & n;

    for (int i = 0; i < n; i++)
    {
        answer[i] = base;
    }

    for (int i = n - remainder; i < n; i++)
    {
        answer[i]++;
    }

    return answer;
}

int main(void)
{
    vector<int> results = solution(2, 9);

    for (int n : results)
    {
        cout << n << endl;
    }

    return 0;
}
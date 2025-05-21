#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main(void)
{
    freopen("alien.txt", "r", stdin);

    int N, P;

    cin >> N >> P;

    int count = 0;

    unordered_map<int, priority_queue<int>> um;

    for (int i = 0; i < N; i++)
    {
        int line, pret;

        cin >> line >> pret;

        if (um[line].empty())
        {
            count++;
            um[line].push(pret);
        }
        else
        {
            while (um[line].top() > pret && !um[line].empty())
            {
                count++;
                um[line].pop();
            }

            if (um[line].top() < pret || um[line].empty())
            {
                um[line].push(pret);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
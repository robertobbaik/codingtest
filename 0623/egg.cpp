#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int result = 0;
vector<bool> visited;
vector<pair<int, int>> egg;

void backtracking(int index)
{
    if (index == N)
    {
        int broken = 0;
        for (int i = 0; i < N; i++)
        {
            if (egg[i].first <= 0)
            {
                broken++;
            }
        }
        result = max(result, broken);
        return;
    }

    if (egg[index].first <= 0)
    {
        backtracking(index + 1);
        return;
    }

    bool ishit = false;
    for (int i = 0; i < N; i++)
    {
        if (i == index || egg[i].first <= 0)
        {
            continue;
        }

        egg[index].first -= egg[i].second;
        egg[i].first -= egg[index].second;

        ishit = true;
        backtracking(index + 1);
        egg[index].first += egg[i].second;
        egg[i].first += egg[index].second;
    }

    if (!ishit)
    {
        backtracking(index + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("egg.txt", "r", stdin);

    cin >> N;

    egg.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++)
    {
        int S, W;

        cin >> S >> W;

        egg[i] = {S, W};
    }

    backtracking(0);

    cout << result << endl;

    return 0;
}
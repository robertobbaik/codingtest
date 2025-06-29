#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> results;
vector<vector<int>> price;

void backtracking(int prev, int sum, int depth)
{
    if (depth == N)
    {
        results.push_back(sum);
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        if(i == prev) continue;
        sum += price[depth][i];
        backtracking(i, sum, depth + 1);
        sum -= price[depth][i];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rgb.txt", "r", stdin);

    cin >> N;

    price.resize(N, vector<int>(3, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> price[i][j];
        }
    }

    backtracking(-1, 0, 0);

    int min = *min_element(results.begin(), results.end());
    cout << min << endl;

    return 0;
}
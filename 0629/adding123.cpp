#include <iostream>
#include <vector>

using namespace std;

void dfs(int sum, int &count, int target)
{
    if (sum == target)
    {
        count++;
        return;
    }

    for (int i = 1; i < 4; i++)
    {
        if (sum + i <= target)
        {
            dfs(sum + i, count, target);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("adding123.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int target;
        cin >> target;

        int count = 0;

        dfs(0, count, target);
        cout << count << "\n";
    }
    return 0;
}
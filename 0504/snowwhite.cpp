#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("snowwhite.txt", "r", stdin);
    vector<int> dwarfs(9);
    vector<int> answer;

    for (int i = 0; i < 9; i++)
    {
        cin >> dwarfs[i];
    }

    for (int mask = 1; mask < (1 << 9); mask++)
    {
        int target = 0;
        int count = 0;
        for (int i = 0; i < 9; i++)
        {
            if (mask & (1 << i))
            {
                count++;
                target += dwarfs[i];
            }
        }

        if (target == 100 && count == 7)
        {
            for (int i = 0; i < 9; i++)
            {
                if (mask & (1 << i))
                {
                    answer.push_back(dwarfs[i]);
                }
            }
            break;
        }
    }

    sort(answer.begin(), answer.end());

    for(int n : answer)
    {
        cout << n << endl;
    }

    return 0;
}

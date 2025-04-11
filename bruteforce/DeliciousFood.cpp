#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    freopen("DeliciousFood.txt", "r", stdin);
    vector<pair<int, int>> flavor;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int S, B;

        cin >> S >> B;
        pair<int, int> p = {S, B};

        flavor.push_back(p);
    }

    int min_num = INT_MAX;

    for (int mask = 1; mask < (1 << N); mask++)
    {
        int s = 1;
        int b = 0;
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                s *= flavor[i].first;
                b += flavor[i].second;
            }
        }

        int gap = abs(s - b);
        min_num = min(gap, min_num);
    }

    cout << min_num << endl;

    return 0;
}
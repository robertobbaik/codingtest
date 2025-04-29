#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("selectnum.txt", "r", stdin);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = 0;
    int best = INT_MAX;

    while (right < N && left < N)
    {
        int interval = v[right] - v[left];

        if(interval >= M)
        {
            best = min(best, interval);
            left++;
        }
        else
        {
            right++;
        }

    }

    cout << best << endl;

    return 0;
}
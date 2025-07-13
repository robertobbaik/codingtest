#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("blog.txt", "r", stdin);

    int N, X;

    cin >> N >> X;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int visit = accumulate(arr.begin(), arr.begin() + X, 0);
    int max_visit = visit;
    int left = 0;
    int right = X;
    unordered_map<int, int> um;
    um[max_visit]++;
    for (int i = 1; i < N - X + 1; i++)
    {
        visit -= arr[i - 1];
        visit += arr[i + X - 1];

        if (max_visit <= visit)
        {
            max_visit = max(max_visit, visit);
            um[max_visit]++;
        }
    }

    if (max_visit == 0)
    {
        cout << "SAD" << endl;
    }
    else
    {
        cout << max_visit << endl;
        cout << um[max_visit] << endl;
    }

    return 0;
}
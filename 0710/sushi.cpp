#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sushi.txt", "r", stdin);

    int N, d, k, c;

    cin >> N >> d >> k >> c;

    vector<int> arr(N);
    vector<int> count(d + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int types = 0;

    for (int i = 0; i < k; i++)
    {
        if (count[arr[i]] == 0)
            types++;
        count[arr[i]]++;
    }

    int max_num = types;
    if (count[c] == 0)
        max_num++;

    for (int i = 1; i < N; i++)
    {
        int prev = arr[i - 1];
        count[prev]--;
        if(count[prev] == 0) types--;

        int next = arr[(i + k - 1) % N];
        if(count[next] == 0) types++;
        count[next]++;

        int current_max = types;
        if(count[c] == 0) current_max++;

        max_num = max(max_num, current_max);
    }

    cout << max_num << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("meetingroom.txt", "r", stdin);

    int N;
    cin >> N;

    vector<pair<int, int>> time;
    for (int i = 0; i < N; i++)
    {
        pair<int, int> t;
        cin >> t.first >> t.second;

        time.push_back(t);
    }

    sort(time.begin(), time.end(), compare);

    int count = 1;

    int end = time[0].second;

    for (int i = 1; i < N; i++)
    {
        if (time[i].first >= end)
        {
            count++;
            end = time[i].second;
        }
    }

    cout << count << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
    return a.first < b.first;
}

int main(void)
{
    freopen("yearsort.txt", "r", stdin);

    int N;

    cin >> N;

    vector<pair<int, string>> vp;

    for(int i = 0; i < N; i++)
    {
        int age;
        string name;

        cin >> age;
        cin >> name;

        vp.push_back({age, name});
    }

    stable_sort(vp.begin(), vp.end(), compare);

    for(int i = 0; i < N; i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }

    return 0;
}
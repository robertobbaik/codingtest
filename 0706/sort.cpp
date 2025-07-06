#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }

    return a.size() < b.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sort.txt", "r", stdin);

    int N;
    cin >> N;
    unordered_set<string> s;
    vector<string> arr;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    for (string str : s)
    {
        arr.push_back(str);
    }

    sort(arr.begin(), arr.end(), compare);

    for (string str : arr)
    {
        cout << str << "\n";
    }

    return 0;
}
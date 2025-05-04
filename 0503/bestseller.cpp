#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("bestseller.txt", "r", stdin);
    int N;

    cin >> N;

    map<string, int> um;

    for (int i = 0; i < N; i++)
    {
        string str;

        cin >> str;

        um[str]++;
    }

    auto it = *max_element(um.begin(), um.end(), [](const pair<string, int>& a, const pair<string, int>& b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    cout << it.first << endl;

    return 0;
}
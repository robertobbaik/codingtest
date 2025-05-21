#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    freopen("unknownperson.txt", "r", stdin);
    int N, M;
    cin >> N >> M;

    map<string, int> m;

    for(int i = 0; i < N + M; i++)
    {
        string name;
        cin >> name;

        m[name]++;
    }

    vector<string> v;

    for(auto it = m.begin(); it != m.end(); ++it)
    {
        if(it->second == 2)
        {
            v.push_back(it->first);
        }
    }

    cout << v.size() << endl;

    for(string s : v)
    {
        cout << s << endl;
    }

    return 0;
}
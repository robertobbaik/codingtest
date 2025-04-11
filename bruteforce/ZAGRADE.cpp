#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

int main(void)
{
    freopen("ZAGRADE.txt", "r", stdin);

    string str;
    cin >> str;

    stack<int> s;
    vector<pair<int, int>> vp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else if (str[i] == ')')
        {
            int openIdx = s.top();
            s.pop();
            vp.push_back({openIdx, i});
        }
    }

    int len = vp.size();
    set<string> results;
    for (int mask = 1; mask < (1 << len); mask++)
    {
        string temp = "";
        set<int> s;
        for (int i = 0; i < len; i++)
        {
            if (mask & (1 << i))
            {
                auto[l, r] = vp[i];
                s.insert(l);
                s.insert(r);
            }
        }

        for(int i = 0; i < str.size(); i++)
        {
            if(s.find(i) == s.end())
            {
                temp += str[i];
            }
        }

        results.insert(temp);
    }
    for (const string& r : results)
    cout << r << endl;

    return 0;
}
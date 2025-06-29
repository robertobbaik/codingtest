#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool getgroupword(string str)
{
    unordered_set<char> um;

    char prev = str[0];
    for(char c : str)
    {
        if(um.find(c) != um.end())
        {
            return false;
        }

        if(c != prev)
        {
            um.insert(prev);
            prev = c;
        }
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("word.txt", "r", stdin);

    int N;
    cin >> N;

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if(getgroupword(str))
        {
            result += 1;
        }
    }

    cout << result << endl;

    return 0;
}
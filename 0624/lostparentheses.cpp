#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lostparentheses.txt", "r", stdin);

    string str;

    cin >> str;

    vector<string> minusParts = split(str, '-');

    int result = 0;

    vector<string> firstPart = split(minusParts[0], '+');

    for (string num : firstPart)
    {
        result += stoi(num);
    }

    for(int i = 1; i < minusParts.size(); i++)
    {
        vector<string> plusParts = split(minusParts[i], '+');
        for(string num : plusParts)
        {
            result -= stoi(num);
        }
    }

    cout << result << endl;

    return 0;
}
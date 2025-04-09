#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    freopen("getalphabetcount.txt", "r", stdin);

    string str;

    cin >> str;

    cout << str << endl;

    int alphabet[26] = {
        0
    };

    for (char c : str)
    {
        if(c == ' ') continue;
        alphabet[c - 'a']++;
    }

    for (int n : alphabet)
    {
        cout << n << " ";
    }

    cout << endl;
}
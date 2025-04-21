#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string str = "banana";

    string a;
    string b;

    for (int i = 0; i < str.size(); i++)
    {
        if (i % 2 != 0)
        {
            a += str[i];
        }
        else
        {
            b += str[i];
        }
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    cout << a << endl;
    cout << b << endl;

    return 0;
}
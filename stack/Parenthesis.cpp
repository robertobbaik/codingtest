#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main(void)
{
    freopen("Parenthesis.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        string ps;
        cin >> ps;

        if (ps.size() % 2 == 0)
        {
            bool isPair = true;
            stack<char> s;
            for (int i = 0; i < ps.size(); i++)
            {
                if (ps[i] == '(')
                {
                    s.push(ps[i]);
                }
                else
                {
                    if (!s.empty())
                    {
                        s.pop();
                    }
                    else
                    {
                        cout << "NO" << '\n';
                        isPair = false;
                        break;
                    }
                }
            }

            if (s.empty() && isPair)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
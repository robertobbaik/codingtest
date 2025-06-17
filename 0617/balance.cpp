#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    freopen("balance.txt", "r", stdin);

    // cout << temp << endl;
    while (true)
    {
        string temp;

        getline(cin, temp);
        string answer = "yes";

        if (temp == ".")
        {
            break;
        }

        stack<char> s;

        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '(' || temp[i] == '[')
            {
                s.push(temp[i]);
            }
            else if (temp[i] == ')')
            {
                if (s.empty())
                {
                    answer = "no";
                    break;
                }
                else
                {
                    if (s.top() == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        answer = "no";
                    }
                }
            }
            else if (temp[i] == ']')
            {
                if (s.empty())
                {
                    answer = "no";
                    break;
                }
                else
                {
                    if (s.top() == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        answer = "no";
                    }
                }
            }
        }

        if (!s.empty())
        {
            answer = "no";
        }

        cout << answer << endl;
    }

    return 0;
}
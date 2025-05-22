#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    freopen("AC.txt", "r", stdin);
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        deque<int> temp;
        string str;
        for (int i = 0; i < x.size(); i++)
        {
            if (isdigit(x[i]))
            {
                str += x[i];
            }
            else if (x[i] == ',' || x[i] == ']')
            {
                if (str == "")
                    continue;
                int n = stoi(str);
                temp.push_back(n);
                str = "";
            }
        }

        bool isError = false;
        bool isReversed = false;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                isReversed = !isReversed;
            }
            else if (p[i] == 'D')
            {
                if (temp.empty())
                {
                    cout << "error" << endl;
                    isError = true;
                    break;
                }
                else
                {
                    if (isReversed)
                    {
                        temp.pop_back();
                    }
                    else
                    {
                        temp.pop_front();
                    }
                }
            }
        }

        if (!isError)
        {
            cout << "[";

            if (!temp.empty())
            {
                if (isReversed)
                {
                    for (int i = temp.size() - 1; i >= 0; i--)
                    {
                        cout << temp[i];
                        if (i != 0)
                        {
                            cout << ",";
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < temp.size(); i++)
                    {
                        cout << temp[i];
                        if (i != temp.size() - 1)
                        {
                            cout << ",";
                        }
                    }
                }
            }

            cout << "]" << endl;
        }
    }

    return 0;
}
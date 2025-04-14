#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long S = 0;

    //freopen("set.txt", "r", stdin);

    int cmd_count;

    cin >> cmd_count;
    for (int i = 0; i < cmd_count; i++)
    {
        string command;
        int num;
        cin >> command;

        //int result = 0;
        if (command == "add")
        {
            cin >> num;
            num -= 1;

            if (((1 << num) & S) == 0)
            {
                S += (1 << num);
            }
        }
        else if (command == "check")
        {
            cin >> num;
            num -= 1;
            if (((1 << num) & S) == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout << "1\n";
            }
            
        }
        else if (command == "toggle")
        {
            cin >> num;
            num -= 1;
            if (((1 << num) & S) == 0)
            {
                S += (1 << num);
            }
            else
            {
                S -= (1 << num);
            }
        }
        else if (command == "remove")
        {
            cin >> num;
            num -= 1;
            if (((1 << num) & S))
            {
                S -= (1 << num);
            }
        }
        else if (command == "all")
        {
            S = (1 << 20) -1;
        }
        else if (command == "empty")
        {
            S = 0;
        }
    }
}
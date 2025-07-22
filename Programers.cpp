#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s  = "[[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[')
        {
            s[i] = '{';
        }
        else if(s[i] == ']')
        {
            s[i] = '}';
        }

    }

    cout << s << endl;


    return 0;
}
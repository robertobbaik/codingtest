#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s  = "[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]";

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
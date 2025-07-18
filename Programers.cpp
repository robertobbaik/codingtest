#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s = "	[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[')
        {
            s[i] = '{';
        }
        else if(s[i]==']')
        {
            s[i] = '}';
        }
    }

    cout << s << endl;

    return 0;
}	
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s = "[[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]]";

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
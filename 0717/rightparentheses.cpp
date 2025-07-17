#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;

    for(char c : s)
    {
        if(c == '(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            if(st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    if(!st.empty())
    {
        return false;
    }
    

    return answer;
}
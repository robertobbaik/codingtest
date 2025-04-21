#include <iostream>
#include <string>

using namespace std;

string solution(string str)
{
    string answer = "";

    bool hasblank = false;
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if(i == 0) c = toupper(c);

        if(hasblank)
        {
            c = toupper(c);
            hasblank = false;
        }
        else
        {
            c = tolower(c);
            hasblank = false;
        }

        if(isblank(c))
        {
            hasblank = true;
        }

        answer += c;
    }

    return answer;
}

int main(void)
{
    string str = "3people unFollowed me";
    string result = solution(str);

    cout << result << endl;

    return 0;
}
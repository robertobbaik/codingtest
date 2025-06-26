#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for(int i = 1; i < phone_book.size(); i++)
    {
        string temp = phone_book[i - 1];
        if(phone_book[i].substr(0, temp.size()) == temp)
        {
            answer = false;
        }
    }

    return answer;
}
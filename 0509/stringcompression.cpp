#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = s.size();

    int count = 1;

    for (int count = 1; count <= s.size() / 2; count++)
    {
        string temp = "";
        string prev = s.substr(0, count);
        int multiple = 1;

        for (int i = count; i < s.size(); i += count)
        {
            if (prev == s.substr(i, count))
            {
                multiple++;
            }
            else
            {
                if (multiple > 1)
                {
                    temp += to_string(multiple) + prev;
                }
                else
                {
                    temp += prev;
                }

                prev = s.substr(i, count);
                multiple = 1;
            }
        }

        if (multiple > 1)
        {
            temp += to_string(multiple) + prev;
        }
        else
        {
            temp += prev;
        }

        answer = min(answer, (int)temp.size());
    }

    return answer;
}

int main(void)
{
    int result = solution("aabbaccc");

    cout << result << endl;

    return 0;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> um;

    for (string str : participant)
    {
        um[str]++;
    }

    for (string str : completion)
    {
        um[str]--;
    }

    for(auto it = um.begin(); it != um.end(); it++)
    {
        if(it->second != 0)
        {
            answer = it->first;
        }
    }



    return answer;
}
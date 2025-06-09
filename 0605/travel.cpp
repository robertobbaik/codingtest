#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(vector<vector<string>>& tickets, string current, vector<string>& route, int count)
{
    if(count == tickets.size())
    {
        
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;



    return answer;
}

int main(void)
{
    vector<string> result = solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});

    for(string s : result)
    {
        cout << s << endl;
    }


    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<vector<string>> &tickets, vector<bool> &used, vector<string> &answer, string current, int totaltickets, bool &found)
{
    if (found)
        return;

    if (answer.size() == totaltickets + 1)
    {
        found = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (found)
            return;
        if (!used[i] && tickets[i][0] == current)
        {
            used[i] = true;
            answer.push_back(tickets[i][1]);
            dfs(tickets, used, answer, tickets[i][1], totaltickets, found);

            if (found)
                return;

            used[i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    vector<bool> used(tickets.size(), false);
    bool found = false;

    sort(tickets.begin(), tickets.end());

    answer.push_back("ICN");

    dfs(tickets, used, answer, "ICN", tickets.size(), found);
    return answer;
}

int main(void)
{
    vector<string> answer = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});

    for (string str : answer)
    {
        cout << str << endl;
    }

    return 0;
}
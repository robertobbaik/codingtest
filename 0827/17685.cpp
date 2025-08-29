#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool canMatch(string user, string banned)
{
    if(user.length() != banned.length()) return false;

    for(int i = 0; i < user.length(); i++)
    {
        if(banned[i] != '*' && banned[i] != user[i])
        {
            return false;
        }
    }

    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, vector<bool>& used, vector<int>& current, set<vector<int>>& results, int idx)
{
    if(idx == banned_id.size())
    {
        vector<int> temp = current;
        sort(temp.begin(), temp.end());
        results.insert(temp);
        return;
    }

    for(int i = 0; i < user_id.size(); i++)
    {
        if(!used[i] && canMatch(user_id[i], banned_id[idx]))
        {
            used[i] = true;
            current.push_back(i);
            dfs(user_id, banned_id, used, current, results, idx + 1);
            current.pop_back();
            used[i]= false;
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    vector<bool> used(user_id.size(), false);
    vector<int> current;
    set<vector<int>> results;

    dfs(user_id, banned_id, used, current, results, 0);

    return results.size();
}

int main(void)
{
    int result = solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"});
    cout << result << endl;
    return 0;
}
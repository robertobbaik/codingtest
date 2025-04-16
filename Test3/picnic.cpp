#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
bool isFound;
int K, N, F;

void dfs(const vector<vector<bool>> &friendsship, vector<int> &friends, int index)
{
    if (isFound)
    {
        return;
    }
        
    if (friends.size() == K)
    {
        isFound = true;
        answer = friends;
        return;
    }

    for (int i = index + 1; i <= N; i++)
    {
        bool isFriends = true;
        for (int j = 0; j < friends.size(); j++)
        {
            if (!friendsship[i][friends[j]])
            {
                isFriends = false;
                break;
            }
        }

        if (isFriends)
        {
            friends.push_back(i);
            dfs(friendsship, friends, i);
            friends.pop_back();
        }
    }
}

int main(void)
{
    //freopen("picnic.txt", "r", stdin);

    cin >> K >> N >> F;

    vector<vector<bool>> friendship(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < F; i++)
    {
        int student1, student2;
        cin >> student1 >> student2;
        friendship[student1][student2] = true;
        friendship[student2][student1] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        vector<int> friends;
        friends.push_back(i);
        dfs(friendship, friends, i);
    }

    if (isFound)
    {
        sort(answer.begin(), answer.end());

        for (int n : answer)
        {
            cout << n << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int team_count = 0;
vector<int> visited;
vector<int> path;

void dfs(const vector<int> &team, int index)
{
    visited[index] = 1;
    path.push_back(index);

    int next = team[index];

    if (visited[next] == 0)
    {
        dfs(team, next);
    }
    else if (visited[next] == 1)
    {
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == next)
            {
                team_count += path.size() - i;
                break;
            }
        }
    }
    visited[index] = 2;
    path.pop_back();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("termproject.txt", "r", stdin);

    int T;

    cin >> T;
    vector<vector<int>> project;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> student(n + 1, 0);

        for (int i = 1; i < n + 1; i++)
        {
            cin >> student[i];
        }

        project.push_back(student);
    }

    for (const auto &v : project)
    {
        team_count = 0;
        visited.assign(v.size(), false);
        path.clear();
        for (int i = 1; i < v.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(v, i);
            }
        }

        cout << (v.size() - 1 - team_count) << endl;
    }

    return 0;
}
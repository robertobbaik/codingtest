#include <iostream>
#include <vector>

using namespace std;

int team_count = 0;
vector<bool> visited;

void dfs(const vector<int> &project, int next, int start)
{
    if (project[next] == start)
    {
        team_count++;
    }
    else
    {
        if (project[next] == next)
            return;

        dfs(project, project[next], start);
    }
}

int main(void)
{
    freopen("termproject.txt", "r", stdin);

    int T;

    cin >> T;

    vector<vector<int>> project;
    while (T--)
    {
        int student_count;
        cin >> student_count;
        vector<int> want_case(student_count + 1, 0);
        for (int i = 0; i < student_count + 1; i++)
        {
            if (i == 0)
                continue;
            cin >> want_case[i];
        }

        project.push_back(want_case);
    }

    for (const auto &v : project)
    {
        visited.clear();
        visited.resize(v.size(), false);
        for (int i = 1; i < v.size(); i++)
        {
            if (!visited[i])
            {
                dfs(v, i, i);
            }
        }

        cout << (v.size() - 1 - team_count) << endl;
        team_count = 0;
    }

    return 0;
}
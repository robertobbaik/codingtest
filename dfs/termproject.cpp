#include <iostream>
#include <vector>

//1	2 3	4 5	6 7
//3	1 3	7 3	4 6

using namespace std;

int team_count = 0;
vector<int> visited;
vector<int> path;

void dfs(const vector<int> &project, int student)
{
    visited[student] = 1; 
    path.push_back(student); 
    int next = project[student]; 

    if(visited[next] == 0)
    {
        dfs(project, next);
    }
    else if(visited[next] == 1)
    {
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == next)
            {
                team_count += path.size() - i;
                break;
            }
        }
    }
    visited[student] = 2;
    path.pop_back();
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
        for (int i = 1; i < student_count + 1; i++)
        {
            cin >> want_case[i];
        }

        project.push_back(want_case);
    }

    for (const auto &v : project)
    {
        team_count = 0;
        visited.assign(v.size(), 0);
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
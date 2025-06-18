#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, int node, int &count, int deleteNode)
{
    if (node == deleteNode)
    {
        return;
    }

    bool isLeaf = true;

    for (int next : graph[node])
    {
        if (next != deleteNode)
        {
            isLeaf = false;
            dfs(graph, next, count, deleteNode);
        }
    }

    if(isLeaf)
    {
        count++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("tree.txt", "r", stdin);

    int N;
    cin >> N;

    vector<vector<int>> graph(N);
    int parentNode = 0;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            parentNode = i;
        }
        else
        {
            graph[n].push_back(i);
        }
    }

    int deleteNode;

    cin >> deleteNode;

    if (deleteNode == parentNode)
    {
        cout << 0 << "\n";
    }
    else
    {
        int count = 0;
        vector<bool> visited(N);
        dfs(graph, parentNode, count, deleteNode);

        cout << count << endl;
    }

    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    int id;
    int x;
    int y;

    Node *left;
    Node *right;

    Node(int _id, int _x, int _y) : id(_id), x(_x), y(_y), left(nullptr), right(nullptr) {}
};

bool compare(const vector<int> &a, const vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }

    return a[1] > b[1];
}

Node *insertNode(Node *root, Node *newNode)
{
    if (root == nullptr)
    {
        return newNode;
    }

    if (newNode->x < root->x)
    {
        root->left = insertNode(root->left, newNode);
    }
    else
    {
        root->right = insertNode(root->right, newNode);
    }

    return root;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), compare);

    Node *root = nullptr;

    for (auto &node : nodeinfo)
    {
        Node *newNode = new Node(node[2], node[0], node[1]);

        root = insertNode(root, newNode);
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> result = solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}});

    
    return 0;
}
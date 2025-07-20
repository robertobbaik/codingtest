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

void preorder(Node *node, vector<int> &result)
{
    if (node == nullptr)
    {
        return;
    }

    result.push_back(node->id);
    preorder(node->left, result);
    preorder(node->right, result);
}

void postorder(Node *node, vector<int> &result)
{
    if (node == nullptr)
    {
        return;
    }

    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->id);
}

void inorder(Node *node, vector<int> &result)
{
    if (node == nullptr)
    {
        return;
    }

    inorder(node->left, result);
    result.push_back(node->id);
    inorder(node->right, result);
    
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
    vector<int> pre;
    preorder(root, pre);
    vector<int> post;
    postorder(root, post);

    vector<int> in;
    inorder(root, in);

    for(int n : pre)
    {
        cout << n << " ";
    }

    cout << endl;

    for(int n : in)
    {
        cout << n << " ";
    }

    cout << endl;

    for(int n : post)
    {
        cout << n << " ";
    }

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main(void)
{
    vector<vector<int>> result = solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}});

    return 0;
}
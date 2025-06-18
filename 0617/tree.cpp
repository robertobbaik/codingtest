#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.acmicpc.net/problem/1991

struct Node
{
    char left;
    char right;
};

unordered_map<char, Node> tree;

void preorder(char node)
{
    if (node == '.')
    {
        return;
    }

    cout << node;
    preorder(tree[node].left);
    preorder(tree[node].right);
}

void inorder(char node)
{
    if (node == '.')
    {
        return;
    }

    inorder(tree[node].left);
    cout << node;
    inorder(tree[node].right);
}

void postorder(char node)
{
    if (node == '.')
    {
        return;
    }
    postorder(tree[node].left);
    postorder(tree[node].right);
    cout << node;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("tree.txt", "r", stdin);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        Node temp;

        temp.left = left;
        temp.right = right;
        tree[parent] = temp;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}
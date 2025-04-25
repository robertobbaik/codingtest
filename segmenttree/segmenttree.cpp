#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> tree;
vector<ll> arr;

ll init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, ll diff)
{
    if (index < start || index > end)
    {
        return;
    }

    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("addrange.txt", "r", stdin);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N);
    tree.resize(N * 4);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int a;
        ll b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            b--; // index 보정
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 0, N - 1, b, diff);
        }
        else
        {
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
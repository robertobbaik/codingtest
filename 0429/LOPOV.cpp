#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int>& a, pair<int,int>& b)
{
    return a.second > b.second;
}

int main(void)
{
    freopen("LOPOV.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    vector<pair<int, int>> p;
    vector<int> v;
    vector<bool> used(K, false);
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;

        p.push_back({first, second});
    }

    for(int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(p.begin(), p.end());
    sort(v.begin(), v.end());

    priority_queue<int> pq; 
    long long answer = 0;
    int j = 0;

    for (int i = 0; i < K; i++) 
    {
        while (j < N && p[j].first <= v[i]) 
        {
            pq.push(p[j].second); 
            j++;
        }

        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";
    
    return 0;
}
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> dq;
    int N, M;
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }
    
    vector<int> targets(M);
    for (int i = 0; i < M; i++)
    {
        cin >> targets[i];
    }
    
    int count = 0;
    
    for (int i = 0; i < M; i++)
    {
        int target = targets[i];
        
        auto it = find(dq.begin(), dq.end(), target);
        int pos = distance(dq.begin(), it);
        
        int leftMove = pos;
        int rightMove = dq.size() - pos;
        
        if (leftMove <= rightMove)
        {
            for (int j = 0; j < leftMove; j++)
            {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
                count++;
            }
        }
        else
        {
            for (int j = 0; j < rightMove; j++)
            {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                count++;
            }
        }
        
        dq.pop_front();
    }
    
    cout << count << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lier.txt", "r", stdin);

    int N, M, T;
    cin >> N >> M >> T;

    unordered_set<int> truth;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        truth.insert(n);
    }

    vector<vector<int>> parties;

    for (int i = 0; i < M; i++)
    {
        int len;
        cin >> len;
        vector<int> arr(len, 0);
        for (int j = 0; j < len; j++)
        {
            cin >> arr[j];
        }
        parties.push_back(arr);
    }

    bool ischanged = true;

    while(ischanged)
    {
        ischanged = false;

        for(int i = 0; i < M; i++)
        {
            bool hasTruth = false;

            for(int p : parties[i])
            {
                if(truth.count(p))
                {
                    hasTruth = true;
                    break;
                }
            }

            if(hasTruth)
            {
                for(int p : parties[i])
                {
                    if(truth.find(p) == truth.end())
                    {
                        truth.insert(p);
                        ischanged = true;
                    }
                }
            }
        }
    }

    int result = 0;
    for(int i = 0; i < M; i++)
    {
        bool canlie = true;
        for(int p : parties[i])
        {
            if(truth.count(p))
            {
                canlie = false;
                break;
            }
        }
        if(canlie)
        {
            result++;
        }
    }

    cout << result << endl;
 

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    freopen("hospital.txt", "r", stdin);

    int N;

    cin >> N;

    vector<int> L;
    vector<int> J;

    int max_joy = 0;

    for(int i = 0; i < N; i++)
    {
        int n;

        cin >> n;
        L.push_back(n);
    }

    for(int i = 0; i < N; i++)
    {
        int n;

        cin >> n;
        J.push_back(n);
    }

    for(int mask = 0; mask < (1 << N); ++mask)
    {
        int hp = 100;
        int joy = 0;

        for(int i = 0; i < N; ++i)
        {
            if(mask & (1 << i))
            {
                hp -= L[i];
                if(hp <= 0) break;
                joy += J[i];
            }
            
        }


        if(hp > 0)
        {
            max_joy = max(max_joy, joy);
        }
    }

    cout << max_joy << endl;


    return 0;
}
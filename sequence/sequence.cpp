#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("sequence.txt", "r", stdin);
    
    int N;

    cin >> N;

    vector<int> A(N, 0);

    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> lis;

    for(int i = 0; i < N; ++i)
    {
        int num = A[i];
        auto it = lower_bound(lis.begin(), lis.end(), num); // lower_bound : 특정값 이상의 배열 인덱스를 반환
        if(it == lis.end())
        {
            lis.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    cout << lis.size() << endl;
    return 0;
}
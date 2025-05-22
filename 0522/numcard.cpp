#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    freopen("numcard.txt", "r", stdin);
    int N;

    cin >> N;
    vector<int> cards(N);
    for(int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }

    int M;
    cin >> M;
    vector<int> cards2(M);
    unordered_map<int, int> m;
    for(int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        cards2[i] = n;
    }

    for(int i = 0; i < N; i++)
    {
        m[cards[i]]++;
    }

    for(int i = 0; i < M; i++)
    {
        cout << m[cards2[i]] << " ";
    }



    return 0;
}
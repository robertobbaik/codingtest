#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("word.txt", "r", stdin);

    int N;
    cin >> N;
    vector<string> words(N);
    for(int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    
    return 0;
}
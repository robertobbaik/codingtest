#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pokemon.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    unordered_map<int, string> um_i;
    unordered_map<string, int> um_s;

    for(int i = 1; i < N + 1; i++)
    {
        string str;
        cin >> str;
        um_i[i] = str;
        um_s[str] = i;
    }

    for(int i = 0; i < M; i++)
    {
        string question;
        cin >> question;

        if(isdigit(question[0]))
        {
            cout << um_i[stoi(question)] << "\n";
        }
        else
        {
            cout << um_s[question] << "\n";
        }
        
    }

    return 0;
}
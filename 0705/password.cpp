#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int L, C;
vector<char> vc;
vector<char> password;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isValid()
{
    int vowels = 0;
    int consonants = 0;

    for (char c : password)
    {
        if (isVowel(c))
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }

    return vowels >= 1 && consonants >= 2;
}

void backtracking(int start, int depth)
{
    if (depth == L)
    {
        if (isValid())
        {
            for (char cha : password)
            {
                cout << cha;
            }

            cout << endl;
        }

        return;
    }

    for (int i = start; i < C; i++)
    {
        password.push_back(vc[i]);
        backtracking(i + 1, depth + 1);
        password.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("password.txt", "r", stdin);

    cin >> L >> C;

    vc.resize(C);

    for (int i = 0; i < C; i++)
    {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    vector<char> temp;

    backtracking(0, 0);
    return 0;
}
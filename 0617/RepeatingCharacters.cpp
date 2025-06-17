#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    freopen("RepeatingCharacters.txt", "r", stdin);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int R;
        cin >> R;
        string str;
        cin >> str;

        string answer;

        for(int j = 0; j < str.size(); j++)
        {
            for(int k = 0; k < R; k++)
            {
                answer += str[j];
            }
        }

        cout << answer << endl;
    }

    return 0;
}

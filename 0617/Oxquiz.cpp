#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    freopen("Oxquiz.txt", "r", stdin);
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string quiz;

        cin >> quiz;

        int answer = 0;
        int weight = 0;
        for(int j = 0; j < quiz.size(); j++)
        {
            if(quiz[j] == 'O')
            {
                answer += 1 + weight;
                weight++;
            }
            else
            {
                weight = 0;
            }
        }
        cout << answer << endl;
    }

    return 0;
}
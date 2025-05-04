#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int temp = N;

    vector<int> answer;

    while (temp--)
    {
        int temp2 = temp;
        int target = 0;

        while (temp2)
        {
            target += temp2 % 10;
            temp2 /= 10;
        }

        if (temp + target == N)
        {
            answer.push_back(temp);
        }
    }
    
    if(answer.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << answer[answer.size()-1] << endl;
    }
}
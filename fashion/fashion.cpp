#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        unordered_map<string, int> um;
        int N;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            string clothes_name, clothes_type;
            cin >> clothes_name >> clothes_type;
            um[clothes_type]++;
        }

        int answer = 1;
        for (auto& pair : um)
        {
            answer *= (pair.second + 1); 
        }

        answer -= 1;

        cout << answer << '\n';
    }

    return 0;
}
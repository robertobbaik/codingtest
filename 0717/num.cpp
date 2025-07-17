#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sum(int left, int right)
{
    int result = (left + right) * (right - left + 1) / 2;
    return result;
}

int solution(int n)
{
    int answer = 0;

    for (int right = 1; right <= n; right++)
    {
        int left = 1;
        while (left <= right)
        {
            int temp = sum(left, right);

            if (temp == n)
            {
                answer++;
            }

            left++;
        }
    }

    return answer;
}

int main(void)
{
    int result = solution(15);
    cout << result << endl;

    return 0;
}
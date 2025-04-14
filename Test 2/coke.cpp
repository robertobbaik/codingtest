#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    int temp = n;
    
    while(temp / a)
    {
        answer += (temp / a) * b;
        temp = (temp / a) * b + temp % a;
    }
    
    return answer;
}

int main(void)
{
    int result = solution(2, 1, 20);

    cout << result << endl;
}
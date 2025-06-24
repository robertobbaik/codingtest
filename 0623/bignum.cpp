#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> v;

    for(int num : numbers)
    {
        v.push_back(to_string(num));
    }

    sort(v.begin(), v.end(), compare);

    for(string s : v)
    {
        answer += s;
    }

    if(answer[0] =='0') return "0";

    return answer;
}

int main(void)
{
    vector<int> numbers = {3, 30, 34, 5, 9};
    string result = solution(numbers);

    cout << result << endl;

    return 0;
}
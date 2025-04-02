#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool compare(string a, string b)
{
    int same_count = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            same_count++;
        }
    }

    return same_count == a.size() - 1;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    vector<bool> visited(words.size(), false);

    queue<pair<string, int>> q;

    q.push({begin, 0});

    while(!q.empty())
    {
        string str = q.front().first;
        int count = q.front().second;

        if(str == target)
        {
            return count;
        }

        q.pop();
    
        for(int i = 0; i < words.size(); i++)
        {
            if(compare(str, words[i]) && !visited[i])
            {
                q.push({words[i], count + 1});
                visited[i] = true;
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = solution("hit", "cog", words);

    cout << result << endl;

    return 0;
}
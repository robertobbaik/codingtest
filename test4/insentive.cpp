#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct score
{
    int a;
    int b;
    int total;
};

bool compare(const score& s1, const score& s2)
{
    if (s1.a == s2.a)
        return s1.b < s2.b;
    return s1.a > s2.a;
}

int solution(vector<vector<int>> scores)
{
    vector<score> v(scores.size());

    score target({scores[0][0], scores[0][1], scores[0][0] + scores[0][1]});

    for (int i = 0; i < v.size(); i++)
    {
        score s({scores[i][0], scores[i][1], scores[i][0] + scores[i][1]});
        v[i] = s;
    }

    sort(v.begin(), v.end(), compare);

    int max = -1;

    vector<score> currentscores;

    for (auto& s : v)
    {
        if (s.b >= max)
        {
            currentscores.push_back(s);
            max = s.b;
        }
    }



    

    int rank = 1;
    int sameRankCount = 1; // 같은 점수 갯수
    int prevTotal = v[0].total;

    if (v[0].a == target.a && v[0].b == target.b)
        return rank;

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i].total == prevTotal)
        {
            sameRankCount++;
        }
        else
        {
            rank += sameRankCount;
            sameRankCount = 1;
            prevTotal = v[i].total;
        }

        if (v[i].a == target.a && v[i].b == target.b)
        {
            return rank;
        }
    }

    return -1;
}

int main(void)
{
    vector<vector<int>> scores = {{2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}};

    int answer = solution(scores);
    cout << answer << endl;
    return 0;
}
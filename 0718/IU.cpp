#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;
int maxMul;

void dfs(long cur, int plusCnt)
{
    if ((int)(log(cur) / log(3)) * 2 < plusCnt)
        return;
    if (cur == 3 && plusCnt == 2)
    {
        cnt++;
        return;
    }
    if (cur < 3)
        return;

    if (cur % 3 == 0 && plusCnt >= 2)
    {
        dfs(cur / 3, plusCnt - 2);
    }

    dfs(cur - 1, plusCnt + 1);
}
int solution(int n)
{
    cnt = 0;
    dfs(n - 2, 2);
    return cnt;
}

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <cmath>

// using namespace std;

// int answer = 0;

// void dfs(string s, int depth, int n, int limit, int starcount)
// {
//     if (depth == limit * 3)
//     {
//         int sum = 1;
//         for (char c : s)
//         {
//             if (c == '*')
//             {
//                 sum *= 3;
//             }
//             else
//             {
//                 sum += 1;
//             }
//         }

//         if (sum == n)
//         {
//             answer++;
//         }
//         return;
//     }

//     if (starcount < limit)
//     {
//         if (s.size() - starcount <= starcount * 2)
//         {
//             dfs(s + '*', depth + 1, n, limit, starcount + 1);
//         }
//     }

//     dfs(s + '+', depth + 1, n, limit, starcount);
// }

// int solution(int n)
// {
//     int limit = cbrt(n);
//     dfs("*", 1, n, limit, 1);

//     return answer;
// }

// int main(void)
// {
//     int result = solution(15);
//     cout << result << endl;
//     return 0;
// }
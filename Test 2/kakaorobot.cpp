#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Robot
{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int rx[4] = {-1, 1, -1, 1};
int ry[4] = {1, -1, -1, 1};

int solution(vector<vector<int>> board)
{
    int answer = 0;

    return answer;
}

int solution2(vector<vector<int>> board)
{
    int answer = 0;
    int N = board.size();

    return answer;
}

int main(void)
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    int result = solution2(board);
    return 0;
}

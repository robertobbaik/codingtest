#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

struct Robot
{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
};

bool isValid(int x, int y, const vector<vector<int>> &board)
{
    int n = board.size();

    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == 0;
}

vector<Robot> getNextPosition(const Robot &r, const vector<vector<int>> &board)
{
    vector<Robot> next;

    int x1 = r.x1;
    int x2 = r.x2;
    int y1 = r.y1;
    int y2 = r.y2;

    int time = r.time;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int rd[2] = {-1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nx1 = x1 + dx[i];
        int nx2 = x2 + dx[i];
        int ny1 = y1 + dy[i];
        int ny2 = y2 + dy[i];

        if (isValid(nx1, ny1, board) && isValid(nx2, ny2, board))
        {
            Robot n_robot;
            n_robot.x1 = nx1;
            n_robot.y1 = ny1;
            n_robot.x2 = nx2;
            n_robot.y2 = ny2;
            n_robot.time = time + 1;
            next.push_back(n_robot);
        }

        if (x1 == x2)
        {
            for (int d : rd)
            {
                if (isValid(x1 + d, y1, board) && isValid(x2 + d, y2, board))
                {
                    next.push_back({x1, y1, x1 + d, y1, time + 1});
                    next.push_back({x2, y2, x2 + d, y2, time + 1});
                }
            }
        }

        if (y1 == y2)
        {
            for (int d : rd)
            {
                if (isValid(x1, y1 + d, board) && isValid(x2, y2 + d, board))
                {
                    next.push_back({x1, y1, x2, y1 + d, time + 1});
                    next.push_back({x2, y2, x2, y2 + d, time + 1});
                }
            }
        }
    }

    return next;
}

int solution(vector<vector<int>> board)
{
    int n = board.size();
    int answer = 0;

    queue<Robot> q;
    set<tuple<int, int, int, int>> visited;
    q.push({0, 0, 0, 1, 0});
    visited.insert({0, 0, 0, 1});

    while(!q.empty())
    {
        Robot robot = q.front();
        q.pop();
        int x1 = robot.x1;
        int y1 = robot.y1;
        int x2 = robot.x2;
        int y2 = robot.y2;
        int time = robot.time;
        
        if((x1 == n-1 && y1 == n-1) || (x2 == n-1 && y2 == n-1))
        {
            return time;
        }

        vector<Robot> vr = getNextPosition(robot, board);

        for(Robot nr : vr)
        {
            int nx1 = nr.x1;
            int ny1 = nr.y1;
            int nx2 = nr.x2;
            int ny2 = nr.y2;

            //auto key = minmax({pair})
        }


    }

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

    int result = solution(board);
    return 0;
}

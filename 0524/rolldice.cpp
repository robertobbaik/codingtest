#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;
vector<vector<int>> board;
vector<int> dice(7, 0); // 1~6번 주사위 면 저장 (0은 사용 안함)

// 방향: 동(1), 서(2), 북(3), 남(4) → 배열 인덱스 0~3
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// 주사위 굴리기
void roll(int dir)
{
    int temp = dice[1];
    if (dir == 0)
    { // 동
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if (dir == 1)
    { // 서
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    else if (dir == 2)
    { // 북
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else if (dir == 3)
    { // 남
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("rolldice.txt", "r", stdin);
    cin >> N >> M >> x >> y >> K;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < K; ++i)
    {
        int cmd;
        cin >> cmd;
        int dir = cmd - 1; // 입력은 1~4 → 0~3

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;

        roll(dir);
        x = nx;
        y = ny;

        if (board[x][y] == 0)
        {
            board[x][y] = dice[6];
        }
        else
        {
            dice[6] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[1] << endl;
    }

    return 0;
}
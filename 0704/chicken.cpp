#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getDistance(pair<int, int> house, pair<int, int> chicken)
{
    return abs(house.first - chicken.first) + abs(house.second - chicken.second);
}

int getTotalDistance(const vector<pair<int, int>> &house, const vector<pair<int, int>> &chicken)
{
    int distance = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int temp = INT_MAX;
        for (int j = 0; j < chicken.size(); j++)
        {
            temp = min(temp, getDistance(house[i], chicken[j]));
        }

        distance += temp;
    }

    return distance;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("chicken.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(N, 0));

    vector<pair<int, int>> chicken;
    vector<pair<int, int>> house;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                house.push_back({i, j});
            }

            if (board[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    int min_distance = INT_MAX;

    vector<bool> select(chicken.size(), false);
    fill(select.end() - M, select.end(), true);

    do
    {
        vector<pair<int, int>> selectedChicken;

        for(int i = 0; i <  chicken.size(); i++)
        {
            if(select[i])
            {
                selectedChicken.push_back(chicken[i]);
            }
        }

        min_distance = min(min_distance, getTotalDistance(house, selectedChicken));
    
    } while (next_permutation(select.begin(), select.end()));
    

    cout << min_distance << endl;

    return 0;
}
// https://www.acmicpc.net/problem/10473

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

double getDistance(pair<float, float> start, pair<float, float> end)
{
    float x = start.first - end.first;
    float y = start.second - end.second;

    return sqrt(pow(x, 2) + pow(y, 2));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("canon.txt", "r", stdin);

    double sx, sy, ex, ey;

    cin >> sx >> sy >> ex >> ey;

    int n;
    cin >> n;

    vector<pair<double, double>> points;
    points.push_back({sx, sy});
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    points.push_back({ex, ey});

    int totalNodes = points.size();
    vector<double> dist(totalNodes, 1e9);

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentDistance > dist[currentNode])
            continue;

        for (int i = 0; i < totalNodes; i++)
        {
            if (currentNode == i)
                continue;

            double newCost;
            double distance = getDistance(points[currentNode], points[i]);

            if (currentNode == 0)
            {
                newCost = distance / 5.0f;
            }
            else
            {
                double walkTime = distance / 5.0f;
                double canonTime = 2.0 + abs(distance - 50.0) / 5.0;
                
                newCost = min(walkTime, canonTime);
            }

            if(dist[currentNode] + newCost < dist[i])
            {
                dist[i] = dist[currentNode] + newCost;
                pq.push({dist[i], i});
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << dist[totalNodes - 1] << endl;
    return 0;
}
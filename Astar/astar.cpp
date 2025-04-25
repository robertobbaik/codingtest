#include <queue>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
// AStarNode 구조체: A* 알고리즘에서 사용되는 노드 구조체로, 좌표, 실제 비용(gCost), 추정 비용(hCost), 부모 정보를 저장
struct AStarNode
{
    int id;            // 노드의 고유 id
    int x, y;          // 노드의 위치(좌표), 격자 기반 맵 등에서 사용
    float gCost;       // 시작점부터 현재 노드까지의 실제 누적 비용
    float hCost;       // 현재 노드부터 목표 노드까지의 예상 비용(휴리스틱 값)
    AStarNode *parent; // 경로 복원에 사용되는 부모 노드 포인터

    // 총 비용 f(n) = g(n) + h(n)
    float fCost() const { return gCost + hCost; }
};

// CompareAStarNode 구조체: 우선순위 큐에서 AStarNode를 fCost 기준으로 비교하기 위한 함수 객체
struct CompareAStarNode
{
    bool operator()(const AStarNode *a, const AStarNode *b) const
    {
        // fCost가 낮은 노드를 우선으로 처리 (최소 힙)
        return a->fCost() > b->fCost();
    }
};

// 휴리스틱 함수: 맨해튼 거리를 사용하여 두 좌표 간의 거리를 추정
float Heuristic(int x1, int y1, int x2, int y2)
{
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

// AStarSearch 함수: startID부터 goalID까지 A* 알고리즘을 사용하여 최적 경로를 찾음
vector<AStarNode *> AStarSearch(vector<AStarNode *> &nodes, int startID, int goalID)
{
    // A* 탐색에 사용할 오픈 리스트: 평가되지 않은 노드를 fCost 기준으로 정렬하여 저장
    priority_queue<AStarNode *, vector<AStarNode *>, CompareAStarNode> openList;
    // 닫힌 리스트: 이미 평가가 완료된 노드를 추적
    vector<bool> closed(nodes.size(), false);

    AStarNode *startNode = nodes[startID]; // 시작 노드
    AStarNode *goalNode = nodes[goalID];   // 목표 노드

    // 시작 노드의 비용 초기화: 시작점이므로 gCost = 0, hCost는 휴리스틱 함수로 계산
    startNode->gCost = 0;
    startNode->hCost = Heuristic(startNode->x, startNode->y, goalNode->x, goalNode->y);
    openList.push(startNode); // 시작 노드를 오픈 리스트에 삽입

    // 오픈 리스트가 빌 때까지 반복
    while (!openList.empty())
    {
        AStarNode *current = openList.top(); // fCost가 가장 낮은 노드를 선택
        openList.pop();

        // 만약 현재 노드가 목표 노드면, 경로 복원 후 반환
        if (current->id == goalID)
        {
            vector<AStarNode *> path;
            // 부모 포인터를 따라가면서 경로를 생성
            while (current != nullptr)
            {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end()); // 경로를 시작→목표 순으로 정렬
            return path;
        }

        closed[current->id] = true; // 현재 노드를 닫힌 리스트에 기록하여 재평가되지 않도록 함

        // 현재 노드에 인접한 이웃 노드들(실제 구현에서는 인접 노드 리스트를 제공해야 함)
        // 여기서는 예시로 빈 벡터(std::vector<AStarNode*>())를 사용함
        for (AStarNode *neighbor : /* current의 인접 노드 목록 */ vector<AStarNode *>())
        {
            // 이미 닫힌 노드라면 건너뜀
            if (closed[neighbor->id])
                continue;

            // 현재 노드에서 이웃 노드로 이동할 때의 비용 계산 (여기서는 두 노드 간의 맨해튼 거리 이용)
            float tentativeG = current->gCost + Heuristic(current->x, current->y, neighbor->x, neighbor->y);

            // 만약 새로 계산한 gCost가 기존 이웃 노드의 gCost보다 작다면, 더 좋은 경로를 발견한 것으로 간주
            if (tentativeG < neighbor->gCost)
            {
                neighbor->parent = current;   // 현재 노드를 부모로 설정
                neighbor->gCost = tentativeG; // gCost 갱신
                // hCost 재계산: 이웃 노드에서 목표 노드까지의 예상 비용
                neighbor->hCost = Heuristic(neighbor->x, neighbor->y, goalNode->x, goalNode->y);
                // 갱신된 이웃 노드를 오픈 리스트에 다시 삽입
                openList.push(neighbor);
            }
        }
    }
    return {}; // 목표 경로를 찾지 못한 경우 빈 벡터 반환
}

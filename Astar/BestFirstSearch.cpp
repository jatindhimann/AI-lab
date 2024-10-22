//  Best First Search considering only g value.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pp;

void BestFirstSearch(vector<vector<int>> &grid, int startNode, int goalNode)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<int> gValues(grid.size(), INT_MAX);
    vector<bool> visited(grid.size(), false);

    pq.push({0, startNode});
    gValues[startNode] = 0;

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currG = pq.top().first;
        pq.pop();

        if (visited[currNode])
            continue;

        visited[currNode] = true;

        cout << currNode << " ";

        if (currNode == goalNode)
        {
            cout << "\nCongrats! We have reached the goal node " << goalNode << endl;
            return;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[currNode][i] != 0 && !visited[i])
            {
                int newG = currG + grid[currNode][i];

                if (newG < gValues[i])
                {
                    gValues[i] = newG;
                    pq.push({newG, i});
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> grid = {
        {0, 6, 3, 1, 0, 0, 0, 0, 0, 0},
        {6, 0, 2, 6, 3, 4, 0, 0, 0, 0},
        {3, 2, 0, 0, 4, 5, 0, 0, 0, 0},
        {1, 6, 0, 0, 7, 8, 9, 0, 0, 0},
        {0, 3, 4, 7, 0, 6, 9, 9, 0, 0},
        {0, 4, 5, 8, 6, 0, 8, 9, 0, 0},
        {0, 0, 0, 9, 9, 8, 0, 11, 12, 14},
        {0, 0, 0, 0, 9, 9, 11, 0, 14, 15},
        {0, 0, 0, 0, 0, 0, 12, 14, 0, 0},
        {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}};

    int startNode = 0;
    int goalNode = 9;

    BestFirstSearch(grid, startNode, goalNode);

    return 0;
}

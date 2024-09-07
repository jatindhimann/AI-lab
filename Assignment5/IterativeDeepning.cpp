// Iterative Deepening by exploring best node first.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pp;

bool DLS(int curNode, int target, int limit, const vector<vector<int>> &adj, vector<int> &gValues, vector<bool> &visited)
{
    if (curNode == target)
        return true;
    if (limit <= 0)
        return false;

    visited[curNode] = true;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({gValues[curNode], curNode});

    while (!pq.empty())
    {
        int nodeId = pq.top().second;
        int currG = pq.top().first;
        pq.pop();

        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[nodeId][i] != 0 && !visited[i])
            {
                int newG = currG + adj[nodeId][i];

                if (newG < gValues[i])
                {
                    gValues[i] = newG;
                    pq.push({newG, i});

                    if (i == target)
                        return true;
                }
            }
        }
    }

    return false;
}

bool IDS(int startNode, int targetNode, int maxDepth, const vector<vector<int>> &adj)
{
    vector<int> gValues(adj.size(), INT_MAX);
    gValues[startNode] = 0;

    for (int i = 1; i <= maxDepth; i++)
    {
        cout << "Searching with depth limit: " << i << endl;
        vector<bool> visited(adj.size(), false);
        if (DLS(startNode, targetNode, i, adj, gValues, visited))
            return true;
    }

    return false;
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
    int maxDepth = 5; 

    if (IDS(startNode, goalNode, maxDepth, grid))
        cout << "Target node " << goalNode << " found!" << endl;
    else
        cout << "Target node " << goalNode << " not found within depth " << maxDepth << "." << endl;

    return 0;
}

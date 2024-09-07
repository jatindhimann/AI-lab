// Iterative Deepening by exploring best node first.
#include <iostream>
#include <vector>
using namespace std;

bool DLS(int curNode, int target, int limit, const vector<vector<int>> &adj, vector<int> &visited)
{
    if (curNode == target)
        return true;
    if (limit <= 0)
        return false;

    visited[curNode] = 1;

    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[curNode][i] != 0 && !visited[i])
        {
            if (DLS(i, target, limit - 1, adj, visited))
                return true;
        }
    }

    return false;
}

bool IDS(int startNode, int targetNode, int maxDepth, const vector<vector<int>> &adj)
{
    for (int depth = 1; depth <= maxDepth; ++depth)
    {
        cout << "Searching with depth limit: " << depth << endl;
        vector<int> visited(adj.size(), 0);
        if (DLS(startNode, targetNode, depth, adj, visited))
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
    int targetNode = 9; 
    int maxDepth = 5;  

    if (IDS(startNode, targetNode, maxDepth, grid))
        cout << "Target node " << targetNode << " found!" << endl;
    else
        cout << "Target node " << targetNode << " not found within depth " << maxDepth << "." << endl;

    return 0;
}

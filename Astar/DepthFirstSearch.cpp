// Depth First Search without considering any cost.
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &grid, int startNode, int goalNode, vector<bool> &visited)
{

    visited[startNode] = true;
    cout << startNode << " ";

    if (startNode == goalNode)
    {
        cout << "\nCongrats! We have reached the goal node " << goalNode << endl;
        return;
    }

    for (int i = 0; i < grid[startNode].size(); ++i)
    {
        if (grid[startNode][i] != 0 && !visited[i])
        {
            DFS(grid, i, goalNode, visited);
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
    vector<bool> visited(grid.size(), false);

    DFS(grid, startNode, goalNode, visited);

    if (!visited[goalNode])
    {
        cout << "\nGoal node " << goalNode << " was not reached." << endl;
    }

    return 0;
}

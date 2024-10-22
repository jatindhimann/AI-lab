#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adj;
    vector<int> visited;
    int nodes;

public:
    Graph(int n) : nodes(n)
    {
        adj.resize(n);
        visited.resize(n, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool DLS(int curNode, int target, int limit)
    {
        if (curNode == target)
            return true;
        if (limit <= 0)
            return false;

        visited[curNode] = 1;

        for (int nextNode : adj[curNode])
        {
            if (!visited[nextNode])
            {
                if (DLS(nextNode, target, limit - 1))
                    return true;
            }
        }

        return false;
    }

    bool IDS(int startNode, int targetNode, int maxDepth)
    {
        for (int depth = 1; depth <= maxDepth; ++depth)
        {
            cout << "Searching with depth limit: " << depth << endl;
            fill(visited.begin(), visited.end(), 0);
            if (DLS(startNode, targetNode, depth))
                return true;
        }

        return false;
    }
};

int main()
{
    int node = 21, edge;
    cout << "Enter the number of edges in the graph: ";
    cin >> edge;

    Graph g(node);

    cout << "Enter the edges (pairs of connected nodes):" << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode, targetNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "Enter the target node: ";
    cin >> targetNode;

    int maxDepth = 3; // We'll check depths from 1 to 3

    cout << "Starting Iterative Deepening Search (IDS)..." << endl;
    if (g.IDS(startNode, targetNode, maxDepth))
    {
        cout << "Target node " << targetNode << " is found within depth " << maxDepth << endl;
    }
    else
    {
        cout << "Target node " << targetNode << " is not found within depth " << maxDepth << endl;
    }

    return 0;
}

/*
Example Input:
20
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
0 15
*/

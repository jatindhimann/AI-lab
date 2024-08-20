#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class graph
{
    unordered_map<int, vector<int>> adjList;
    vector<bool> visited;
    int number_of_nodes;

public:
    graph(int number_of_nodes)
    {
        this->number_of_nodes = number_of_nodes;
        visited.resize(number_of_nodes, false);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int src)
    {
        visited[src] = true;
        cout << src << " ";

        for (auto &nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                dfs(nbr);
            }
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for (auto &nbr : adjList[front])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void resetVisited()
    {
        fill(visited.begin(), visited.end(), false);
    }
};

int main()
{
    graph g(10);
    int src;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 7);
    cout << "Enter source Node ";
    cin >> src;
    cout << "DFS starting from Node: " << src << endl;

    g.dfs(src);
    cout << endl;

    g.resetVisited();

    cout << "BFS starting from Node: " << src << endl;
    g.bfs(src);
    cout << endl;

    return 0;
}
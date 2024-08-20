#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

class Graph
{
    int numVertices;

public:
    vector<vector<int>> adjacencyMatrix;

    Graph(int vertices)
    {
        numVertices = vertices;
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; i++)
            adjacencyMatrix[i][i] = INF;
    }

    void inputGraph()
    {
        cout << "Enter adjacency matrix:\n";
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cin >> adjacencyMatrix[i][j];
                if (i == j)
                    adjacencyMatrix[i][j] = INF;
            }
        }
    }
};

vector<int> BFS_level_limited(Graph &graph, int maxLevelWidth)
{
    int numVertices = graph.adjacencyMatrix.size();
    queue<int> vertexQueue;
    vector<int> bfsOrder;
    vector<int> visited(numVertices, 0);
    int startVertex;

    cout << "Enter the start vertex: ";
    cin >> startVertex;

    vertexQueue.push(startVertex);
    visited[startVertex] = 1;

    while (!vertexQueue.empty())
    {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();
        bfsOrder.push_back(currentVertex);

        for (int i = 0; i < numVertices && vertexQueue.size() < maxLevelWidth; i++)
        {
            if (!visited[i] && graph.adjacencyMatrix[currentVertex][i] == 1)
            {
                vertexQueue.push(i);
                visited[i] = 1;
            }
        }
    }
    return bfsOrder;
}

vector<int> BFS_node_limited(Graph &graph, int maxNodeWidth)
{
    int numVertices = graph.adjacencyMatrix.size();
    queue<int> vertexQueue;
    vector<int> bfsOrder;
    vector<int> visited(numVertices, 0);
    int startVertex;

    cout << "Enter the start vertex: ";
    cin >> startVertex;

    vertexQueue.push(startVertex);
    visited[startVertex] = 1;

    while (!vertexQueue.empty())
    {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();
        bfsOrder.push_back(currentVertex);
        int nodeCount = 0;

        for (int i = 0; i < numVertices && nodeCount < maxNodeWidth; i++)
        {
            if (!visited[i] && graph.adjacencyMatrix[currentVertex][i] == 1)
            {
                vertexQueue.push(i);
                visited[i] = 1;
                nodeCount++;
            }
        }
    }
    return bfsOrder;
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    Graph graph(numVertices);
    graph.inputGraph();

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Constant width at level\n";
        cout << "2. Constant width at node\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter maximum width for level: ";
            int maxLevelWidth;
            cin >> maxLevelWidth;
            vector<int> bfsOrder = BFS_level_limited(graph, maxLevelWidth);
            cout << "\nBFS Traversal with constant width at level:\n";
            for (int vertex : bfsOrder)
                cout << vertex << "\t";
            cout << "\n\n";
            break;
        }
        case 2:
        {
            cout << "\nEnter maximum width for node: ";
            int maxNodeWidth;
            cin >> maxNodeWidth;
            vector<int> bfsOrder = BFS_node_limited(graph, maxNodeWidth);
            cout << "\nBFS Traversal with constant width at node:\n";
            for (int vertex : bfsOrder)
                cout << vertex << "\t";
            cout << "\n\n";
            break;
        }
        case 3:
            exit(0);
        default:
            cout << "Invalid choice. Exiting...\n";
            exit(1);
        }
    }

    return 0;
}

/*
Sample input
10
0 1 1 0 0 1 0 0 0 0
1 0 1 1 0 0 0 0 0 0
1 1 0 0 1 0 0 1 0 0
0 1 0 0 1 0 1 0 1 0
0 0 1 1 0 1 1 0 0 0
1 0 0 0 1 0 0 0 0 1
0 0 0 1 1 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 1 0 0 1 0
*/

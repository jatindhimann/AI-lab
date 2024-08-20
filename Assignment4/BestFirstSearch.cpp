#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <functional>
using namespace std;

class Graph
{
    vector<vector<int>> adjMatrix;

public:
    Graph()
    {
        adjMatrix.resize(28, vector<int>(28, 0));
    }

    int idx(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            return ch - 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            return ch - 'a';
        }
        else if (ch == ' ')
        {
            return 26;
        }
        else if (ch == '.')
        {
            return 27;
        }
        return -1;
    }

    void createGraph(string s)
    {
        int n = s.length();
        for (int i = 0; i < n - 1; i++)
        {
            int from = idx(s[i]);
            int to = idx(s[i + 1]);

            if (from != -1 && to != -1)
            {
                adjMatrix[from][to]++;
            }
        }
    }

    void print()
    {
        cout << setw(4) << " ";
        for (int i = 0; i < 28; i++)
        {
            if (i < 26)
                cout << setw(4) << char('A' + i);
            else if (i == 26)
                cout << setw(4) << "SP";
            else
                cout << setw(4) << ".";
        }
        cout << endl;

        for (int i = 0; i < 28; i++)
        {
            if (i < 26)
                cout << setw(4) << char('A' + i);
            else if (i == 26)
                cout << setw(4) << "SP";
            else
                cout << setw(4) << ".";

            for (int j = 0; j < 28; j++)
            {
                cout << setw(4) << adjMatrix[i][j];
            }
            cout << endl;
        }
    }

    void bestFirstSearch(char startChar)
    {
        int start = idx(startChar);
        if (start == -1)
        {
            cout << "Invalid start character." << endl;
            return;
        }

        vector<bool> visited(28, false);
        priority_queue<pair<int, int>> pq;

        pq.push({0, start});
        visited[start] = true;

        cout << "Best-First Search Order starting from " << startChar << ":\n";

        while (!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();

            if (curr < 26)
                cout << char('A' + curr) << " ";
            else if (curr == 26)
                cout << "SP ";
            else
                cout << ". ";

            for (int i = 0; i < 28; i++)
            {
                if (adjMatrix[curr][i] > 0 && !visited[i])
                {
                    pq.push({adjMatrix[curr][i], i});
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g;
    string str;

    cout << "Enter a string to create the graph: ";
    getline(cin, str);

    g.createGraph(str);
    g.print();

    char ch;
    cout << "Enter a source node: ";
    cin >> ch;

    g.bestFirstSearch(ch);

    return 0;
}


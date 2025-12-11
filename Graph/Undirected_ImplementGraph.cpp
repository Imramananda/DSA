#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
    int V;
    unordered_map<int, list<int>> adjList;

public:
    Graph(int v) : V(v)
    {
        cout << "Ctor" << endl;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjusencyList()
    {
        cout << "Print list using Map " << endl;
        for (auto i:adjList)
        {
            cout << "vertex : " << i.first<< " : ";
            for (auto n: i.second)
            {
                cout << n << " , ";
            }
            cout << endl;
        }
    }

    void BFS()
    {

    }
};

int main()
{
    cout << "Undirected Graph " << endl;
    Graph obj(5);
    obj.addEdge(0, 1);
    obj.addEdge(1, 2);
    obj.addEdge(1, 3);
    obj.addEdge(2, 3);
    obj.addEdge(2, 4);
    obj.printAdjusencyList();
    return 0;
}
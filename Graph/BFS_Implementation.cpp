#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>

using namespace std;

class BFSTraversal
{
    unordered_map<int, list<int>> g;
    unordered_map<int, bool> vis;  // Use map instead of vector

    public:
    BFSTraversal()
    {
        cout<<"Ctor"<<endl;
    }
    void graph(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void print()
    {
        for(auto &i:g)
        {
            cout<<"Vertex : "<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    
    void BFS(int start)
    {
        queue<int> q;
        vis[start] = true;
        q.push(start);
        
        cout << "BFS Traversal: ";
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            //cout<<"understang : "<<g[node]<<endl;
            // Visit all neighbors of current node
            for(auto neighbor : g[node])
            {
                if(!vis[neighbor])
                {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    cout<<"Here is the graph "<<endl;
    BFSTraversal obj;
    obj.graph(0,1);
    obj.graph(1,2);
    obj.graph(1,3);
    obj.graph(2,3);
    obj.graph(2,4);

    obj.print();
    cout << endl;
    obj.BFS(0);  // Start BFS from vertex 0
    
    return 0;
}
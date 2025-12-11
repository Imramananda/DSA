#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class DFSTraversal
{

    unordered_map<int,list<int>>graph;
    unordered_map<int,bool>vis;

    public:
    void CreateGraph(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void DFS(int src)
    {
        cout<<src<<",";
        vis[src]=true;
        for(auto i:graph[src])
        {
            if(!vis[i])
            DFS(i);
        }
    }
    
    void clearVisited()
    {
        vis.clear();
    }
    
    void BFS(int start)
    {
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(q.size()>0)
        {
            int node = q.front();
            cout<<node<<" , ";
            q.pop();
            for(auto i:graph[node])
            {
                if(!vis[i])
                {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }

};

int main()
{

    cout<<"Here is the graph "<<endl;
    DFSTraversal obj;
    obj.CreateGraph(0,1);
    obj.CreateGraph(1,2);
    obj.CreateGraph(1,3);
    obj.CreateGraph(2,4);
    cout<<"DFS "<<endl;
    obj.DFS(0);
    
    obj.clearVisited();  // Clear visited nodes before BFS
    
    cout<<endl<<"BFS "<<endl;
    obj.BFS(0);
    return 0; 
}
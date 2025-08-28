#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std;

class Graph{
int V; //size
list<int>* l; //neighbors
public:
Graph(int V){
this->V=V;
l=new list<int>[V];
}

void addEdge(int u,int v){  //undirected
l[u].push_back(v);   //if - directed this only
l[v].push_back(u);
}

void print(){
for(int u=0;u<V;u++){
list<int>nbrs=l[u];
cout<<u<<" : ";
for(int v:nbrs){
cout<<v<<" ";
}
}
}

    void bfs() {
    queue<int>q;
    vector<bool>vis(V,false);
    q.push(0);
    vis[0]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        list<int>nbrs=l[u];
        for(int v:nbrs) {
            if (!vis[v]) {
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
    void dfs(int u,vector<bool>&vis) { //u=src
 vis[u]=true;
cout<<u<<" ";
    list<int>nbrs=l[u];
    for(int v:nbrs) {
        if(!vis[v])
            dfs(v,vis);
    }
}
bool hasPath(int src,int dest,vector<bool>&vis) {
    if(src==dest) return true;
    vis[src]=true;
    list<int>nbrs=l[src];
    for (int v:nbrs) {
        if (!vis[v])
          if (hasPath(v,dest,vis)) return true;
    } return false;
}

};

int main(){
    Graph graph(8);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 7);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.print();
    cout<<endl;
    graph.bfs();
    cout<<endl;
    vector<bool>vis(8,false);
    graph.dfs(0,vis);
    cout<<endl;
    vector<bool>viss(8,false);
  cout<<graph.hasPath(0,6,viss);
return 0;
}

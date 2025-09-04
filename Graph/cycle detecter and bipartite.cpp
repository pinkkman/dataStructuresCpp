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
//g++ bin.cpp -o bin && bin



class Graph {
    int V; //size
    list<int> *l; //neighbors
    bool isUndir;  //true means undirectional
public:
    Graph(int V,bool isUndir=true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndir=isUndir;
    }

    void addEdge(int u, int v) {
        //undirected
        l[u].push_back(v); //if - directed this only
        if (isUndir)
            l[v].push_back(u);
    }

    //undirected
    bool cycdethelper(int src, vector<bool> &vis, int par) {
        vis[src] = true;
        list<int> nbrs = l[src];
        for (int v: nbrs) {
            if (!vis[v]) {
                if (cycdethelper(v, vis, src))
                    return true;
            } else { //visited
                if (v != par) return true; //condition of cycle
            }
        }
        return false;
    }

    bool cycledet() {
        vector<bool> vis(V, false);
        return cycdethelper(0, vis, -1);
    }

    //directed
bool cycleDirHelper(int src,vector<bool>vis,vector<bool>rec) {
        vis[src]=true;
        rec[src]=true;
        list<int>nbrs=l[src];
        for (int v:nbrs) {
            if (!vis[v]) {
                vis[v]=true;
                if (cycleDirHelper(v,vis,rec)) return true;

            }else {
                if (rec[v]) return true;
            }
        }
       rec[src]=false;
        return false;
    }

    bool cycleDir() {
        vector<bool>vis(V,false);
        vector<bool>rec(V,false);
        for (int i=0;i<V;i++) {
            cycleDirHelper(0,vis,rec);
        }
    }

bool bipartite() {  //0-blue 1-white
        queue<int>q;
        vector<bool>vis(V,false);
        vector<int>color(V,-1);
       q.push(0);
        color[0]=0;
        while (!q.empty()) {
            int curr=q.front();
            q.pop();
list<int>nbrs=l[curr];
            for (int v:nbrs) {
                if (!vis[v]) {   //not visited
                    vis[v]=true;
                    color[v]=!color[curr];
                    q.push(v);
                }else {         //visited
                    if (color[v]==color[curr])  //breaking point
                        return false;           //same color
                }
            }
        }
return true;
    }

};

int main() {

    // //graph 1
    // graph.addEdge(1,6);
    //     graph.addEdge(6,4);
    //     graph.addEdge(4,3);
    //     graph.addEdge(4,9);
    //     graph.addEdge(3,7);
    //     graph.addEdge(3,8);
    //
    // //graph 2
    //     graph.addEdge(2,5);
    //     graph.addEdge(2,0);
    Graph g(4);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

cout<<g.bipartite();
    return 0;
}

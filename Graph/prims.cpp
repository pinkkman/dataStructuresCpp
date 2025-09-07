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
    list<pair<int,int>>* l; //neighbor ->  wt ,v
public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    }

    void addEdge(int u,int v,int wt){  //undirected
        l[u].push_back(make_pair(wt,v));   //if - directed this only
        l[v].push_back(make_pair(wt,u));
    }

    void prims(int src) {
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap
vector<bool>mst(V,false);

pq.push(make_pair(0,src));   //wt,v
        int ans=0;

        while (!pq.empty()) {
        int wt=pq.top().first;
            int u=pq.top().second;
        pq.pop();
if(!mst[u]) {
    mst[u]=true;
    ans+=wt;
    list<pair<int,int>>nbrs= l[u];
for (pair<int,int>n : nbrs) {
    int currwt=n.first;
    int v=n.second;
    pq.push(make_pair(currwt,v));
}
}
        }
cout<<ans;
        }

    };

int main() {
Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);

    g.prims(0);

    return 0;
}

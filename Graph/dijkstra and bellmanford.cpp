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

class Edge {
public:
    int v;
    int wt;
    Edge(int v,int wt) {
        this->v=v;
        this->wt=wt;
    }
};

void dijkstra(int src,vector<vector<Edge>>graph,int V) {
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;//min heap
//pq-> dist,V
    vector<int>dist(V,INT_MAX);
    pq.push(make_pair(0,src));
    dist[src]=0;
    while (!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        vector<Edge>edge=graph[u];
        for (Edge e:edge ) {
            if (dist[e.v]>dist[u]+ e.wt) { //edge relaxation
                dist[e.v]=dist[u]+ e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }
    for (int d:dist) {
        cout<<d<<" ";
    } cout<<endl;
}

void bellmanford(vector<vector<Edge>>graph,int src,int V) {
vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for (int i=0;i<V-1;i++) {
        for(int u=0;u<V;u++) {
            for (Edge e:graph[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v]=dist[u]+ e.wt ;
                }
            }
        }
    }
    for (int d:dist) {
      cout<<d<<" ";
    }
}


int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    // sample graph (same as dry run wala)
    // A=0, B=1, C=2, D=3, E=4

    graph[0].push_back(Edge(1, 2)); // A-B
    graph[0].push_back(Edge(2, 5)); // A-C
    graph[1].push_back(Edge(0, 2));
    graph[1].push_back(Edge(2, 1)); // B-C
    graph[1].push_back(Edge(3, 2)); // B-D
    graph[2].push_back(Edge(0, 5));
    graph[2].push_back(Edge(1, 1));
    graph[2].push_back(Edge(3, 3)); // C-D
    graph[2].push_back(Edge(4, 1)); // C-E
    graph[3].push_back(Edge(1, 2));
    graph[3].push_back(Edge(2, 3));
    graph[3].push_back(Edge(4, 2)); // D-E
    graph[4].push_back(Edge(2, 1));
    graph[4].push_back(Edge(3, 2));

    cout << "Shortest distances from A (node 0): ";
    dijkstra(0, graph, V);
 bellmanford(graph,0,V);

    return 0;
}

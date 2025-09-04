void toposorthelper(int src,vector<bool>&vis,stack<int>&s){
vis[src]=true;
        list<int>nbrs=l[src];
        for(int v:nbrs) {
            if (!vis[v]) {
                toposorthelper(v,vis,s);
            }
        }
s.push(src);
    }

    void toposort() {
vector<bool>vis(V,false);
        stack<int>s;
       for (int i=0;i<V;i++) {
if(!vis[i]) {
    toposorthelper(i,vis,s);
}
       }
while (!s.empty()) {
    cout<<s.top()<<"  ";
    s.pop();
}
    }

    void calcIndegree(vector<int>&indegree) {
        for (int i=0;i<V;i++) {
            list<int>nbrs=l[i];
            for (int v:nbrs) { // u -> v
                indegree[v]++;
            }
        }
    }

    void toposort2() {
        vector<int>indeg;
        calcIndegree(indeg);
queue<int>q;
        for (int i=0;i<V;i++) {
         if (indeg[i]==0) {
             q.push(i);
         }
        }
        while (!q.empty()) {
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int>nbrs=l[curr];
            for (int v:nbrs) {
                indeg[v]--;
                if (indeg[v]==0) q.push(v);
            }
        }
        }
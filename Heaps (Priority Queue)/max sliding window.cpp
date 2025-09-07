
vector<int> maxslidingwindow(vector<int>arr,int k){ //  O(klogn)
    vector<int>ans;
priority_queue<pair<int,int>>pq;  //value,idx
for(int i=0;i<k;i++){
    pq.push(make_pair(arr[i],i));
}
ans.push_back(pq.top().first);
for(int i=k;i<arr.size();i++){
    while(!pq.empty() && pq.top().second<=i-k){
pq.pop();
    }
pq.push(make_pair(arr[i],i));
   ans.push_back(pq.top().first);
}
}
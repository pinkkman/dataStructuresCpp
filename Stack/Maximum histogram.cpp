//max area in histogram
//next smaller right
vector<int> nsr(vector<int>arr){
  int n=arr.size();
  vector<int>ans(n);
  stack<int>s;
  for(int i=n-1;i>=0;i--){
  while(!s.empty() && arr[i]<=arr[s.top()]){
    s.pop();
  }
  if(s.empty()){
    ans[i]=n;
  }else{
    ans[i]=s.top();
  }
  s.push(i);

  }return ans;
}

//next smaller left
vector<int> nsl(vector<int>arr){
  int n=arr.size();
  vector<int>ans(n);
  stack<int>s;
  for(int i=0;i<n;i++){
  while(!s.empty() && arr[i]<=arr[s.top()]){
    s.pop();
  }
  if(s.empty()){
    ans[i]=-1;
  }else{
    ans[i]=s.top();
  }
s.push(i);
  }return ans;
}
//
int maxhist(vector<int>arr){
  int n=arr.size();
vector<int>left=nsl(arr);
vector<int>right=nsr(arr);
int mx=0;
for(int i=0;i<n;i++){
  int ans=arr[i] * (right[i]-left[i]-1);
  //     height  *  width
  mx=max(mx,ans);
}
return mx;
}


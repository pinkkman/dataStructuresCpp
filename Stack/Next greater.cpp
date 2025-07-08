
vector<int> nextgreater(vector<int>arr){
  int n=arr.size();
vector<int>ans(n);
stack<int>s;
for(int i=n-1;i>=0;i--){
while(!s.empty() && arr[i]>=s.top()){  //removing extra elements from stack
  s.pop();
}

if(s.empty()){
  ans[i]=-1;
}
else{       //next greater found
  ans[i]=s.top();
}s.push(arr[i]);
}
return ans;
}
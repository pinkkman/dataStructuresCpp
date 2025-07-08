
vector<int> stockspan(vector<int>arr){
  int n=arr.size();
vector<int>vec(n);
stack<int>s;

for(int i=0;i<n;i++){
  while(!s.empty() && arr[i]>=arr[s.top()]){  //emptying stack if uselesss lowest prevoius elements found
    s.pop();
  }
  if(s.empty()){
    vec[i]=i+1;     //magic span if no prev highest found or first check
  }
  else{
    vec[i]=i-s.top();  //distance from prev highest
  }
  s.push(i);
}return vec;
}


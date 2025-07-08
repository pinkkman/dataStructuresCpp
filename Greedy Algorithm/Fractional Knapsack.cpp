#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include <algorithm>

using namespace std;

//greedy algorithm
//fracctional knapsack

bool compare(pair<double,int>p1,pair<double,int>p2){
  return p1.first>p2.first;  //sorted desc the  ratio
}

int fk(vector<int>v,vector<int>w,int tw){
  int n=v.size();
  double ans=0.0;
  vector<pair<double,int>>r(n);  //pair of ratio and index(idx)
  for(int i=0;i<n;i++){
    double ratio=(v[i]/w[i]);   
r[i]=make_pair(ratio,i);
  }

sort(r.begin(),r.end(),compare);  //sorted in descending wrt ratio
  
  for(int i=0;i<n;i++){     //bharna start kro higher value se
    int idx=r[i].second;
    if(w[idx]<=tw){
ans+= w[idx] * r[i].first;   //value = ratio * weight
tw-=w[idx];
    }else{
      ans+=tw * r[i].first;
      tw=0;
      break;
    }
  }
return ans;
}


int main(){
vector<int>value={100,60,120};
vector<int>weight={20,10,30};
cout<<fk(value,weight,50);

  return 0;
}
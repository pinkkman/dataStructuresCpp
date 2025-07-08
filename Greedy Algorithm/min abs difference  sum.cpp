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

//min abs 

int main(){
vector<int>a={4,1,8,7};
vector<int>b={2,3,6,5};

int ans=0;
sort(a.begin(),a.end());
sort(b.begin(),b.end());
vector<pair<int,int>>p(a.size());
for(int i=0;i<a.size();i++){
p[i]=make_pair(a[i],b[i]);
}
for(int i=0;i<a.size();i++){
cout<<p[i].first<<" , "<<p[i].second<<endl;
ans+=abs(p[i].first-p[i].second);
}

cout<<" ans = "<<ans;
  return 0;
}
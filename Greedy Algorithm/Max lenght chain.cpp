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

//max lenght chain

bool compare(pair<int,int>p1,pair<int,int>p2){
return p1.second < p2.second;
}

void mlc(vector<pair<int,int>>p){
sort(p.begin(),p.end(),compare);  //end desc

int ans=1;
cout<<p[0].first<<" , "<<p[0].second<<endl;
for(int i=1,idx=0;i<p.size();i++){
  if(p[idx].second<=p[i].first){
   cout<<p[i].first<<" , "<<p[i].second<<endl;
   idx=i;
   ans++;
  }
}
cout<<ans;
}


int main(){
vector<pair<int,int>>p(5);
p[0]=make_pair(5,24);
p[1]=make_pair(39,60);
p[2]=make_pair(5,28);
p[3]=make_pair(27,40);
p[4]=make_pair(50,90);

mlc(p);

  return 0;
}
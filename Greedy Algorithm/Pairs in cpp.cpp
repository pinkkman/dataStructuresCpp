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

//pairs in cpp
bool compare(pair<int,int>p1,pair<int,int>p2){
return p1.second < p2.second;   //sec asc
// return p1.second > p2.second;  //sec desc

// return p1.first < p2.first;    //first asc
// return p1.first > p2.first;   //first desc
}

int main(){

vector<int>start={0,1,2};
vector<int>end={5,9,4};  

vector< pair<int,int> >act(3,make_pair(0,0)); // 0,0  0,0  0,0

act[0]=make_pair(0,5);
act[1]=make_pair(1,9);
act[2]=make_pair(2,4);

for(int i=0;i<act.size();i++){
cout<<"A"<<i<<"  "<<act[i].first<<" , "<<act[i].second<<endl;
}

sort(act.begin(),act.end(),compare);  //sorted the scond element of every pair in ascending order

cout<<"----------sorted------------"<<endl;

for(int i=0;i<act.size();i++){
cout<<"A"<<i<<" - "<<act[i].first<<" , "<<act[i].second<<endl;

}
  return 0;
}
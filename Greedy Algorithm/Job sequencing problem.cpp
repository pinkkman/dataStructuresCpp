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
//job sequencing problem

bool compare(pair<int,int>p1,pair<int,int>p2){
return p1.second > p2.second;  //desc end
}

void js(vector<pair<int,int>>p){
int ans=0,c=0;
sort(p.begin(),p.end(),compare);   //desc end

for(int i=0;i<p.size();i++){
if(p[i].first>c){
  ans+=p[i].second;
  cout<<p[i].first<<" , "<<p[i].second<<endl;
  c++;
}
}
cout<<"Maximum profit : "<<ans;

}

int main(){

vector<pair<int, int>> p = {
    {10, 20},  // Job J1: deadline = 10, profit = 20
    {9, 15},   // Job J2: deadline = 9,  profit = 15
    {8, 10},   // Job J3: deadline = 8,  profit = 10
    {7, 5},    // Job J4: deadline = 7,  profit = 5
    {6, 1}     // Job J5: deadline = 6,  profit = 1
};

js(p);
  return 0;
}
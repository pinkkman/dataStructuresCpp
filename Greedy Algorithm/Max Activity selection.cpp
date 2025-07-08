#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<deque>
using namespace std;


//greedy algorithm
//activity selection or maximum meetings

int as(vector<int>st , vector<int>en){
  //sort first on the basis of end
  for(int i=0;i<st.size()-1;i++){
    for(int j=0;j<st.size()-i;j++){
    if(en[j]>en[j+1]){
swap(en[j],en[j+1]);
swap(st[j],st[j+1]);
    }
  }
  }
  
int ans=1;
//count the non overlapping activities
cout<<st[0]<<" - "<<en[0] <<endl;
for(int i=1,currendidx=0;i<st.size()-1;i++){
  if(en[currendidx]<=st[i]){
    cout<<st[i]<<" - "<<en[i]<<endl;
    ans++;
    currendidx++;
  }
}
return ans;
}

int main(){

vector<int>start={0, 1, 3, 5, 5, 8};
vector<int>end={6, 2, 4, 7, 9, 9};  
cout<<as(start,end);
  return 0;
}
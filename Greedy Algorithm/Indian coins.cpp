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

//indian coins

int ic(vector<int>arr,int v){
  int ans=0;
for(int i=arr.size()-1;i>=0;i--){
while(arr[i]<=v){
  ans++;
cout<<arr[i]<<endl;
v-=arr[i];
} 
}return ans;
}



int main(){
vector<int>arr={1, 2, 5, 10, 20, 50, 100, 500, 2000};
int value=590;
cout<<ic(arr,value);
  return 0;
}
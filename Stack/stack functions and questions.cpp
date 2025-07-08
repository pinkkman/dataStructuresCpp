#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
using namespace std;
//stack 
void pushatbottom(stack<int>&s,int val){
if(s.empty()){
  s.push(val);
  return;
} 
  int top=s.top();
  s.pop();
  pushatbottom(s,val);
  s.push(top);
}

string revstr(string str){
  string ans;
  stack<char>s;
  for(int i=0;i<str.size();i++){
    s.push(str[i]);
  }
  while(!s.empty()){
ans.push_back(s.top());
    s.pop();
  }
  return ans;
}

void revstack(stack<int>s){
if(s.empty()) return;

int temp=s.top();
s.pop();
revstack(s);
pushatbottom(s,temp);  
}


vector<int> stockspan(vector<int>arr){
  int n=arr.size();
vector<int>ans(n);
stack<int>s;   //isme humlg index put krnge 

for(int i=0;i<n;i++){
  while(!s.empty() && arr[i]>=arr[s.top()]){  //emptying stack if uselesss lowest prevoius elements found
    s.pop();
  }
  if(s.empty()){
    ans[i]=i+1;     //magic span if no prev highest found or first check
  }
  else{
    ans[i]=i-s.top();  //distance from prev highest
  }
  s.push(i);
}return ans;
}


int main(){
stack<int> s;
// s.push(2);
// s.push(5);
// s.push(9);
// pushfront(s,7);
// s.push(4);
// pushfront(s,3);

// revstack(s);
// while(!s.empty()){
//   cout<<s.top()<<"  ";
//   s.pop();
// }
vector<int>arr={100,80,60,70,60,85,100};
vector<int >ans=stockspan(arr);
for(int i=0;i<arr.size();i++){
cout<<ans[i]<<"   ";
}    
return 0;
}
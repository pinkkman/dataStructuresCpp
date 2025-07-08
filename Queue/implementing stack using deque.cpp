#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<deque>

using namespace std;
//queue
// stack using deque

class Stack{
deque<int>q;
public:
void push(int val){
q.push_back(val);
}

void pop(){
q.pop_back();
}

int top(){
return q.back();
}

bool empty(){
return q.empty();
}
};

int main(){
Stack q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
q.push(7);
q.push(8);
q.push(9);
q.push(10);

while(!q.empty()){
  cout<<q.top()<<"  ";
  q.pop();
}
  return 0;
}
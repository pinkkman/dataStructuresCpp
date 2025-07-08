#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue
//queue using two stacks

class Queue{
  public:
  stack<int>s1;
  stack<int>s2;

  void push(int val){
    //s1->s2
while(!s1.empty()){
s2.push(s1.top());
s1.pop();
}

s1.push(val);
//s2->s1
while(!s2.empty()){
  s1.push(s2.top());
  s2.pop();
}
  }

  void pop(){
s1.pop();

  }

int front(){
return s1.top();
  }
  bool empty(){
    return s1.empty();
  }
};


int main(){
Queue q;
q.push(2);
q.push(8);
q.push(4);

while(!q.empty()){
  cout<<q.front()<<"  ";
  q.pop();
}
  return 0;
} 
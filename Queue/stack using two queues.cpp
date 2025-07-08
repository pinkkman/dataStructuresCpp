#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue
//stack using two queues

class Queue{
  public:
queue<int>q1;
queue<int>q2;

  void push(int val){
   // q1->q2
while(!q1.empty()){
  q2.push(q1.front());
}
//push value in q1
  q1.push(val);
  
  //q2->q1
  while(!q2.empty()){
q1.push(q2.front());
  }
  }

  void pop(){
q1.pop();
}

int front(){
return q1.front();

  }
  bool empty(){
    return q1.empty();
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
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue
// interleave 2 halves of a queue (even)

queue<int> inter(queue<int>q1){
queue<int>q2;
int n=q1.size();
for(int i=0;i<n/2;i++){
  // q1/2 -> q2
  q2.push(q1.front());
  q1.pop();
}
//q2= 1st half
//q1= 2nd half

//interleave both half queues
for(int i=1;i<=n;i++){
if(i%2!=0){  //odd // q2pop q1add
q1.push(q2.front());
q2.pop();
}else{     //even // q1pop q1 add
q1.push(q1.front());
q1.pop();
}
}
return q1;
}


int main(){
queue<int>q;
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

q=inter(q);
while(!q.empty()){
  cout<<q.front()<<"  ";
  q.pop();
}

  return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue

//using linkd list
class node{
  public:
int data;
node* next;

node(int val){
data=val;
next=NULL;
}
};

class Queue{
  public:
node* head;
node* tail;

Queue(){
  head=NULL;
  tail=NULL;
}

void push(int val){
node* nn= new node(val);
if(head==NULL){
  head=tail=nn;
}
else{
tail->next=nn;
tail=nn;
}
}

void pop(){
  if(empty()) return;
  node* temp=head;
  head=head->next;
  delete temp;
}

int front(){
return head->data;
}

bool empty(){
  return head==NULL;
}
};




int main(){
  Queue q;
q.push(7);
q.push(5);
q.push(1);
while(!q.empty()){
  cout<<q.front()<<"  ";
  q.pop();
}
  return 0;
}
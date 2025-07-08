#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue
//fixed capacity array rotated
//using arrays
class Queue{
  int* arr;
int f,r;
int capacity,currsize;

public: 
Queue(int capacity){
this->capacity=capacity;
arr=new int[capacity];
currsize=0;
f=0;
r=-1;
}

void push(int val){
if(currsize==capacity) return;
r=(r+1) % capacity; //increment //by this when the index reaches last it will come to first making it a rotated array queue
arr[r]=val;
currsize++;
}

void pop(){
  if(currsize==0){
    cout<<"empty";
    return;
  }
  f=(f+1)% capacity;
  currsize--;
}
int front(){
if(empty())return -1;

return arr[f];
}


bool empty(){
return currsize==0;
}
};


int main(){
Queue q(5);
q.push(3);
q.push(4);
q.push(9);
q.push(0);
q.push(1);
cout<<q.front();
q.pop();
cout<<q.front();
  return 0;
}
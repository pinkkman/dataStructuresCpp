#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
//stack 
//using linked list

template<class T>
class node{
  public:  
  int data;
  node* next;
  node(T val){
    data=val;
    next=NULL;
  }
};

template<class T>
class stack{
    public:
    node<T>* head;    //template class
    
stack(){
  head=NULL;
}

    void push(T val){
      node<T>* nn= new node<T>(val);
 if(head==NULL){
  head=nn;
 }else{
  nn->next=head;
  head=nn;
 }
    }

    void pop(){
    node<T>* temp;
    temp=head;
    head=head->next;
    temp->next=NULL;
delete temp;
    }

T top(){
   return head->data;
}

bool isempty(){
  return head==NULL;
}

};

int main(){
stack<int> s;
s.push(2);
s.push(5);
s.push(9);
while(!s.isempty()){
  cout<<s.top()<<"  ";
  s.pop();
}
    return 0;
}
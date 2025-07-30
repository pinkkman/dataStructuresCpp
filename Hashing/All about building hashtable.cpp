#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
#include<unordered_map>
using namespace std;

class node{
    public:
string key;
int val;
node* next;
node(string key,int val){
    this->key=key;
    this->val=val;
    next=nullptr;
}
~node(){
    if(next!=nullptr){
        delete next;
    }
}
};

int hashfunc(string key,int totsz){
int idx=0;
for(int i=0;i<key.size();i++){
    idx+= (key[i] * key[i]) % totsz;
}
return idx%totsz;
}

class hashtable{
int totsz;
int currsz;
node* *table;

public:
hashtable(int size=5){
totsz=size;
currsz=0;
table=new node*[totsz];

for(int i=0;i<totsz;i++){
table[i]=nullptr;
}
}

void rehash(){
node* *oldtable=table;
int oldsz=totsz;
totsz=totsz*2;
table= new node*[totsz];
for(int i=0;i<totsz;i++){
    table[i]=nullptr;
}

//copy old values
for(int i=0;i<oldsz;i++){
node* temp=oldtable[i];
while(temp!=nullptr){
insert(temp->key,temp->val);
temp=temp->next;
}
}
delete[] oldtable;
}

void insert(string key,int val){
int idx=hashfunc(key,totsz);
node* newnode =new node(key,val);
newnode->next=table[idx];
table[idx]=newnode;
currsz++;

double lambda=currsz/(double)totsz;
if(lambda>1){
    rehash();
}
}

void erase(string key){
int idx=hashfunc(key,totsz);
node* temp=table[idx];
node* prev=temp;
while(temp!=nullptr){
    if(temp->key==key){
if(prev==temp){ //head
table[idx]=temp->next;
}else{
    prev->next=prev->next->next;
}
prev=temp;
    temp=temp->next;
}
}
}

bool exists(string key){
int idx=hashfunc(key,totsz);
node* temp=table[idx];
while(temp!=nullptr){
    if(temp->key==key){
        return true;
    }
    temp=temp->next;
}
return false;
}

int search(string key){ //returns the value
int idx=hashfunc(key,totsz);
node* temp=table[idx];
while(temp!=nullptr){
    if(temp->key==key){
        return temp->val;
    }
    temp=temp->next;
}
return -1;
}

void print(){
for(int i=0;i<totsz;i++){
node* temp=table[i];
cout<<"Index : "<<i<<" - ";
while(temp!=nullptr){
    cout<<temp->key<<" - "<<temp->val<<"  "; 
    temp=temp->next; 
}cout<<endl;
}
}

};

int main(){
hashtable h;
h.insert("india",110);
h.insert("china",120);
h.insert("US",100);
h.insert("nepal",10);
h.insert("Dubai",210);
h.insert("japan",20);
h.insert("UK",90);

h.print();

    return 0;
}
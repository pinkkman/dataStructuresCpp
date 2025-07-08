#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Linked list

class node{
    public:
int data;
node *next;   //stores the adress of next element

node(int val){
data=val;
next=NULL;   //till now we do not know the adress of next element
}

~node(){           //deleting node

    if(next!=NULL){
        delete next;
        next=NULL;
    }
}
};


class LL{
    node* head;
    node* tail;

    public:
    LL(){
        head=NULL;
        tail=NULL;
    }
     
    ~LL(){             //deleting ll
        // cout<<"~LL";
        if(head!=NULL){
            delete head;;
            head=NULL;
        }
    }

    void push_front(int val){
    node* nn= new node(val);   //dynamic storing
    
    if(head==NULL){
        head=tail=nn;
    }else{
        nn->next=head;
        head=nn;
    }}


    void push_back(int val){
node* nn= new node(val);

if(head==NULL){
    head=tail=nn;
}else{
    tail->next=nn;
    tail=nn;
} }


void printLL(){
    node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"  ";
    temp=temp->next;
    }
    cout<<endl;
}


void insert(int val,int pos){
node* nn= new node(val);
node* temp=head;
for(int i=0;i<pos-1;i++){
temp=temp->next;
}
nn->next=temp->next;
temp->next=nn;
}


void pop_front(){
   node* temp=head;
   head=temp->next;
   delete temp;
   temp=NULL; 
}

void pop_back(){
    node* temp=head;
    while(temp->next->next!=NULL){  //same as(temp->next!=tail)
        temp=temp->next;
    }
    temp->next=NULL;   //temp=tail's previous
    delete tail;
    tail=temp;
}

//iteraive search
int searchitr(int key){
    node* temp=head;
for(int i=0;temp!=NULL;i++){
if(temp->data==key){
    return i;
} temp=temp->next;
}return -1;
}

//recursive search 
int helper(node* h,int key){   //h=head
if(h==NULL) return -1;
if(h->data==key)  return 0;
int idx=helper(h->next,key);
if(idx==-1)return -1;  
return idx+1;    //every time increment idx hence it increases until the key was found
}
 
int searchrec(int key){      
    return helper(head,key);
}

//reverse a linked list (without using extra space)
                   //prev curr next ,,current ko pura traverse karana hai!!
void rev(){
node * prev=NULL;
node* curr=head;

while(curr!=NULL){   
node* next=curr->next;
curr->next=prev;    //only curr will do the work
prev=curr;
curr=next; 
}
head=prev;
}


//find and remove nth node from end
void fnr(int n){
node* temp=head;
int size=0;
while(temp!=NULL){ //count the size
    temp=temp->next;
size++;
}
node* prev=head;
for(int i=1;i<(size-n);i++){
    prev=prev->next;
}
int del=prev->next->data;
cout<<"Deleted the node "<<del<<endl;
prev->next=prev->next->next;  //prev ka next is now pointing on prev ka next ka next
}
};



int main(){
LL g;
g.push_front(2);
g.push_front(0);
g.push_front(7);
g.insert(21,1);
g.printLL();
// g.pop_front();
// g.printLL();;
g.fnr(1);
g.printLL();

    return 0;
}
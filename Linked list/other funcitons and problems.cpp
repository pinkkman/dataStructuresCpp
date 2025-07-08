#include<iostream>
#include<vector>
#include<string>
#include<list>
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
    public:
    node* head;
    node* tail;


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



bool detectloop(node* head){
node* slow=head;
node* fast=head;
while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast= fast->next->next;
if(fast==slow){
    cout<<"cycle exists";
    return true;
}
}
cout<<"cycle doesnt exist";
return false;
}

void removeloop(node* head){
    //detect loop
node* slow=head;
node* fast=head;
int h=0;
while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast= fast->next->next;
if(fast==slow){
h=1;
}}
//  remove loop
if(h!=1) {
    return ;
}
    node* prev;
    slow=head;
    if(slow==fast){        //full cycle
        while(fast!=slow){
            prev=fast;
            fast=fast->next;
        }
    }else{                 //not full cycle

while(fast!=slow){
    prev=fast;    //last node before entering loop
slow=slow->next;
fast=fast->next;

} }

prev->next=NULL;    //removing the connection of last node hence breaking the loop
}



///merge sort in linked list
//merging two 
node* merge(node* left,node* right){
    if(left==NULL)return right;
    if(right==NULL)return left;
node* result;

if(left->data<=right->data){
    result =left;
    result->next= merge(left->next,right);
}else{
    result =right;
    result->next=merge(left,right->next);
}
return result;
}

//splitting from middle //if odd the first half will be lesser
//return the first element of 2nd half
node* split(node* head){
    node*  slow=head;
    node* fast=head;
    node* prev=NULL;
    while( fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL; //split into two
    }
return slow;   // right head
}
// merge func

node* mergesort(node* head){
if(head==NULL || head->next==NULL) return head;

node* rhead=split(head);
node* left=mergesort(head);   //left sorted
node* right=mergesort(rhead);   //right sorted
return merge(left,right);
}


///zigzag

node* reverse(node* head){
    node* prev=NULL;
    node* curr=head;

    while(curr!=NULL){
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

//zig-zag linked list
node* zigzag(node* head){
     if (!head || !head->next) return head;

    node* rhead=split(head);
    node* revrhead= reverse(rhead); //after reversing
    //alternate or zigzag merge
    node* left=head;
    node* right=revrhead;
    node* tail=NULL;

while(left!=NULL && right!=NULL){
        node* nleft=left->next;
    node* nright=right->next;

left->next=right;
right->next=nleft;
tail=right;

left=nleft;
right=nright;
}
if (right != NULL && tail != NULL) {
    tail->next = right;
}
return head;
}

};

int main(){
LL ll;
ll.push_back(3);
ll.push_back(2);
ll.push_back(7);
ll.push_back(1);
ll.printLL();
ll.head=ll.mergesort(ll.head);

ll.printLL();
ll.head=ll.zigzag(ll.head);
ll.printLL();
    return 0;
}
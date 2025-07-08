#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *intersectPoint(Node *head1, Node *head2) {
 Node* temp1=head1;
 Node* temp2=head2;
 Node* ans=nullptr;
  int c1=0,c2=0;
  while(temp1!=NULL){
temp1=temp1->next;
c1++;
  }

  while(temp2!=NULL){
    temp2=temp2->next;
    c2++;
  }
  temp1=head1;
  temp2=head2;
int c=max(c1,c2);

  while(c!=0){
if(c1==c2){
if(temp1==temp2){
  ans=temp1;
  break;
}
temp1=temp1->next;
temp2=temp2->next;
}
else if(c1>c2){
temp1=temp1->next;
c1--;
}
else if(c1<c2){
temp2=temp2->next;
c2--;
}
c--;
  }
return ans;
}

int main() {
    Node* common = new Node(100);
    common->next = new Node(200);

    // Both lists start from the same node
    Node* head1 = common;
    Node* head2 = common;
    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *intersectPoint(Node *head1, Node *head2) {
 Node* temp1=head1;
 Node* temp2=head2;
 Node* ans=nullptr;
  int c1=0,c2=0;
  while(temp1!=NULL){
temp1=temp1->next;
c1++;
  }

  while(temp2!=NULL){
    temp2=temp2->next;
    c2++;
  }
  temp1=head1;
  temp2=head2;
int c=max(c1,c2);

  while(c!=0){
if(c1==c2){
if(temp1==temp2){
  ans=temp1;
  break;
}
temp1=temp1->next;
temp2=temp2->next;
}
else if(c1>c2){
temp1=temp1->next;
c1--;
}
else if(c1<c2){
temp2=temp2->next;
c2--;
}
c--;
  }
return ans;
}

int main() {
    Node* common = new Node(100);
    common->next = new Node(200);

    // Both lists start from the same node
    Node* head1 = common;
    Node* head2 = common;
    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}
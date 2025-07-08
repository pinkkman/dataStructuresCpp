// C++ Program to sort a linked list of 0s, 1s or 2s

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
   
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node* head) {
int arr[3]={0,0,0};
  Node* temp=head;
  int i;
  while(temp!=NULL){
     i=temp->data;
  arr[i]++;  
    temp=temp->next;
  }
  delete temp;
  Node* temp2=head;

for(int k=0;temp2!=NULL;k++){
  while(arr[k]!=0){
  temp2->data=k;
    temp2=temp2->next;
    arr[k]--;
  }
}
  
}
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


int main() {

    // Create a hard-coded linked list:
    // 1 -> 1 -> 2 -> 1 -> 0 -> NULL 
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printList(head);

    sortList(head);

    cout << "Linked List after Sorting:";
    printList(head);

    return 0;
}
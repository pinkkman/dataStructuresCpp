#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

class node{
public:
int data;
node* left;
node* right;
node(int val){
    this->data=val;
    left=right=NULL;
}

};

node* insert(node* root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
if(val<root->data){
    root->left=insert(root->left,val);
}else{
    root->right=insert(root->right,val);
}
return root; 
}

node* buildbst(int arr[],int n){
node* root=NULL;
for(int i=0;i<n;i++){
    root=insert(root,arr[i]);
}
return root;
}

void inorder(node* root){
if(root==nullptr)return;
inorder(root->left);
cout<<root->data<<"  ";
inorder(root->right);
}

bool search(node* root,int key){
if(root==nullptr) return false ;
    if(root->data==key) return true;

    if(root->data<key) return search(root->right,key);
   else return search(root->left,key);

return false;
}

//delete node
node* inordersucc(node* root){
    if(root->left==nullptr)return root;
    return inordersucc(root->left);
}

node* delnode(node* root,int val){
if(root==NULL)return NULL;

if(root->data > val){
    root->left=delnode(root->left,val);
}else if(root->data < val){
    root->right=delnode(root->right,val);
}else{ //found the node to delete
//case 1: 0 child
if(root->left==nullptr && root->right==nullptr){ //leaf node 
    delete root ;
    return nullptr;
}
///case 2: 1 child
else if(root->right==nullptr || root->left==nullptr){ 
     //returning the valid node not null
    return root->right==nullptr ? root->left : root->right;
}else{
    //case 3: two childs #IMP
node* IS=inordersucc(root->right);
root->data=IS->data;
root->right=delnode(root->right,IS->data);  //case 1 or case 2
return root;
} 
}
}
//

void printinrange(node* root,int st,int en){  
if(root==nullptr)return ;
//3 cases :
if(root->data >=st && root->data<=en){
    //inorder printing
        printinrange(root->left,st,en);
    cout<<root->data<<"  ";
    printinrange(root->right,st,en);
}else if(root->data<st){
    printinrange(root->right,st,en);
}else if(root->data>en){
    printinrange(root->left,st,en);
}
}

void root2leaf(node* root){
      static vector<int>path;
        if(root==nullptr) return;
      path.push_back(root->data);
    if(root->left==nullptr && root->right==nullptr){ //iff leaf node
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<"  ";
    }cout<<endl;
    path.pop_back();
    return;
}
    root2leaf(root->left);
    root2leaf(root->right);

path.pop_back();
}

bool validbst(node* root,node* min,node* max){
    if(root==NULL)return true;

 if(min!=NULL && root->data <= min->data)return false; //repetation
 if(max!=NULL && root->data >= max->data)return false;//not allowed (<=,>=)

   return validbst(root->left,min,root) && validbst(root->right,root,max);

}

int main(){
int arr[]={5,1,3,4,2,7};
int arr2[] = {10,5,8};
node* root=buildbst(arr2,3);
inorder(root);
cout<<endl;
cout<<validbst(root,NULL,NULL);

    return 0;
}
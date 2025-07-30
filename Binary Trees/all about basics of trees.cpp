#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;

class node{
    public:
int data;
node* left;
node* right;
node(int data){
    this->data=data;
    left = right = NULL;
}
};


node* buildTrees(vector<int>nodes){  //return the root node //parent
static int idx=-1;
idx++;
if(nodes[idx]==-1){
    return NULL;
}
    node* currnode=new node(nodes[idx]);
      currnode->left= buildTrees(nodes);
      currnode->right= buildTrees(nodes);
return currnode;
}

void preorder(node* root){  
if(root==NULL) return ;

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(node* root){
if(root==NULL)return ;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

void postorder(node* root){
if(root==NULL)return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";  
}

void levelorder(node* root){
queue<node* >q;
q.push(root);
q.push(NULL);
node* curr;
while(!q.empty()){
curr=q.front();
q.pop();
if(curr==NULL){
    cout<<endl;
    if(q.empty()){
        break;
    }else{
        q.push(NULL);
    }
}
else{
cout<<curr->data<<"  ";
if(curr->left!=NULL) q.push(curr->left);
if(curr->right!=NULL) q.push(curr->right);
}
}
}

int height(node* root){
if(root==NULL) return 0;

int lh=height(root->left);
int rh=height(root->right);
int curr=max(lh,rh) + 1;
return curr;
}

int count(node* root){
if(root==NULL)return 0;
int lc=count(root->left);
int rc=count(root->right);
int c=lc+rc+1;
    return c;
}

int sum(node* root){
if(root==NULL)return 0;
int ls=sum(root->left);
int rs=sum(root->right);
return ls+rs+root->data;
}

int main(){
vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
node* root=buildTrees(nodes);

cout<<"root = "<<root->data<<endl;

cout<<"preorder"<<endl;
preorder(root);
cout<<endl;

cout<<"inorder"<<endl;
inorder(root);
cout<<endl;

cout<<"postorder"<<endl;
postorder(root);
cout<<endl;

cout<<"level-order"<<endl;
levelorder(root);

cout<<"height : "<<height(root);
cout<<endl;

cout<<"count : "<<count(root);
cout<<endl;

cout<<"sum : "<<sum(root);
cout<<endl;

    return 0;
}
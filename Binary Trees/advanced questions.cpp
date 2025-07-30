#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
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
return currnode;  //root
}

void preorder(node* root){  //dfs
if(root==NULL) return ;

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
    
}


void kthHelper(node* root, int k ,int currl){
if(root==NULL)return;
if(currl==k){
    cout<<root->data<<"  ";
    return;
}
kthHelper(root->left,k,currl+1);
kthHelper(root->right,k,currl+1);
}

void kthLevel(node* root,int k){
    kthHelper(root,k,1);
    cout<<endl;
}

bool path(node* root,int n,vector<int> &pathn){
if(root==NULL){
    return false;
}
pathn.push_back(root->data);
if(root->data==n){
    return true;
}
bool isleft=path(root->left,n,pathn);
bool isright=path(root->right,n,pathn);
if(isleft || isright){
    return true;
}
pathn.pop_back();
return false;
}

int lca(node* root,int n1,int n2){
vector<int>path1,path2;
path(root,n1,path1);
path(root,n2,path2);
int lca=-1;
for(int i=min(path1.size(),path2.size());i>=0;i--){
    if(path1[i]==path2[i]){
        lca=path1[i];
        break;
    }
}
return lca;
}

node* lca2(node* root,int n1,int n2){
if(root==NULL)return NULL;
if(root->data==n1 || root->data==n2)return root;

node* leftlca=lca2(root->left,n1,n2);
node* rightlca=lca2(root->right,n1,n2);

if(leftlca && rightlca){
    return root;
}

return leftlca==NULL ?rightlca : leftlca;
}


int kthancestor(node* root,int tar,int k){
if(root==nullptr)return -1;

if(root->data==tar) return 1;

int left=kthancestor(root->left,tar,k);
int right=kthancestor(root->right,tar,k);

if(left==-1 && right==-1){
    return -1;
}
int valid = left==-1 ? right : left;
if(valid==k){
    cout<<"kth ancestor : "<<root->data;
}
return valid + 1;
}


int main(){
vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
node* root=buildTrees(nodes);

// cout<<"root = "<<root->data<<endl;
// node* subroot=new node(5);
// // subroot->left=new node(4);
// // subroot->right=new node(5);

// if(issubroot(root,subroot)) 
// cout<<"yes";
// else cout<<"no";
// cout<<endl;

// topview(root);

// cout<<"preorder"<<endl;
// preorder(root);
// cout<<endl;

// cout<<"height : "<<height(root);
// cout<<endl;

// int d=diam(root).first;
// cout<<"Diameter : "<<d;
// cout<<endl;
kthLevel(root,2);

kthancestor(root,5,2);
    return 0;
}
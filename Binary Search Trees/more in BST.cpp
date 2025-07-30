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

node* balbsthelper(vector<int> arr,int st,int en){
    if(st>en)return nullptr;
int mid=st+(en-st)/2;
node* currnode=new node(arr[mid]);
currnode->left=balbsthelper(arr,st,mid-1); //left call
currnode->right=balbsthelper(arr,mid+1,en);
return currnode;
}

node* balancedbst(vector<int> arr,int n){
   return balbsthelper(arr,0,n-1);
}

void getinorder(node* root,vector<int>&path){
if(root==nullptr){
    return;
}
getinorder(root->left,path);
path.push_back(root->data);
getinorder(root->right,path);
}

node* convtobalbst(node* root){
    vector<int>path;
 getinorder(root,path);
 int n=path.size();
 return balancedbst(path,n);
}

class info{
    public:
    bool isbst;
    int min;
    int max;
    int sz;

    info(bool isbst,int min,int max,int sz){
        this->isbst=isbst;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};

static int maxsz;
static int largestroot;

info* largestbst(node* root){
if(root==nullptr){
    return new info(true,INT_MAX,INT_MIN,0); //leaf node hamesha valid bst hota hai!!
}
    info* leftinfo=largestbst(root->left);
    info* rightinfo=largestbst(root->right);

   int currmin=min({leftinfo->min,rightinfo->min,root->data});
   int currmax=max({leftinfo->max,rightinfo->max,root->data});
   int currsz= leftinfo->sz + rightinfo->sz + 1; 

if(leftinfo->isbst && rightinfo->isbst 
&& root->data > leftinfo->max 
&& root->data < rightinfo->min ){
if(currsz>maxsz){
    maxsz=currsz;
    largestroot=root->data;
}
return new info(true,currmin,currmax,currsz);
}

return new info(false,currmin,currmax,currsz);
}

node* mergebst(node* root1,node* root2){
vector<int>nodes1;
vector<int>nodes2;
vector<int>merged;

getinorder(root1,nodes1);
getinorder(root2,nodes2);
int i=0,j=0;
while(i<nodes1.size() && j<nodes2.size()){
if(nodes1[i]<nodes2[j]){
    merged.push_back(nodes1[i++]);
}else{
    merged.push_back(nodes2[j++]);
}
}
while(i<nodes1.size()){
    merged.push_back(nodes1[i++]);
}
while(j<nodes2.size()){
    merged.push_back(nodes2[j++]);
}
return balancedbst(merged,merged.size());

}


int main() {
    node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(4);

    node* root2 = new node(9);
    root2->left = new node(3);
    root2->right = new node(12);
node* root=mergebst(root1,root2);
inorder(root);
    return 0;
}

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

int height(node* root){
if(root==NULL)return 0;

return max(height(root->left) , height(root->right)) + 1;    
}

///
int diameter(node* root){
    if(root==NULL) return 0;

int currd=height(root->left) + height(root->right) + 1;
int ld=diameter(root->left);
int rd=diameter(root->right);

return max({currd,ld,rd});
}

pair<int,int>diam(node* root){
if(root==NULL){
    return make_pair(0,0);
}

//diameter , height
pair<int,int>li=diam(root->left);
pair<int,int>ri=diam(root->right);

int currdr=li.second +ri.second +1;
int finaldr=max({li.first,currdr,ri.first}); //main target
int finalht=max(li.second,ri.second)+1;

return make_pair(finaldr,finalht);
}

bool isidentical(node* root1,node* root2){
if(root1==NULL && root2==NULL) return true;   //BC
else if(root1==NULL || root2==NULL) return false;

if(root1->data!=root2->data) return false;

 return isidentical(root1->left , root2->left) 
 && isidentical(root1->right , root2->right);
}


bool issubroot(node* root,node* subroot){

if(root==NULL && subroot==NULL)return true;
else if(root==NULL || subroot==NULL)return false;

if(root->data==subroot->data){
    if(isidentical(root,subroot)){
        return true;
    } //agar false return kia to further subtrees me check krna hai !!
}

bool isleft=issubroot(root->left,subroot);
if(!isleft){
    return issubroot(root->right,subroot);
}
return true;
}

void topview(node* root){
queue<pair<node* , int>>q;  // node, horizontal distance
map<int,int>m;              // horzl distance ,node->data
q.push(make_pair( root , 0 ));
while(!q.empty()){
    pair<node*,int> curr=q.front();
    q.pop();
  node* currnode=curr.first;
  int currhd=curr.second;
if(m[currhd]==0){
    m[currhd]=currnode->data;
}
if(currnode->left!=NULL){
    q.push(make_pair(currnode->left,currhd-1));
}
if(currnode->right!=NULL){
    q.push(make_pair(currnode->right,currhd+1));
}
}
for(auto it:m){
    cout<<it.second<<"  ";
}cout<<endl;
}


int main(){
vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
node* root=buildTrees(nodes);

cout<<"root = "<<root->data<<endl;
node* subroot=new node(5);
// subroot->left=new node(4);
// subroot->right=new node(5);

if(issubroot(root,subroot)) 
cout<<"yes";
else cout<<"no";
cout<<endl;

topview(root);

// cout<<"preorder"<<endl;
// preorder(root);
// cout<<endl;

// cout<<"height : "<<height(root);
// cout<<endl;

// int d=diam(root).first;
// cout<<"Diameter : "<<d;
// cout<<endl;


    return 0;
}
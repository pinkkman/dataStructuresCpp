#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<climits>
using namespace std;

//
// class node{
//     public:
// int data;
// node* left;
// node* right;
// node(int data){
//     this->data=data;
//     left = right = NULL;
// }
// };
//
//
// node* buildTrees(vector<int>nodes){  //return the root node //parent
// static int idx=-1;
// idx++;
// if(nodes[idx]==-1){
//     return NULL;
// }
//     node* currnode=new node(nodes[idx]);
//       currnode->left= buildTrees(nodes);
//       currnode->right= buildTrees(nodes);
// return currnode;
// }
//
// void preorder(node* root) {
//     if(root==nullptr)return ;
//     cout<<root->data;
//     preorder(root->left);
//     preorder(root->right);
// }
//
// void bfs(node* root) {
//     if (root==nullptr) return ;
// queue<node*>q;
//     if (root->data)q.push(root);
//     q.push(nullptr);
// while (!q.empty()) {
//     node* curr=q.front();
//     q.pop();
//     if (curr==nullptr) {
//         if (q.empty())break;
//         q.push(nullptr);
//         cout<<endl;
//     } else {
//         cout<<curr->data;
//         if (curr->left) q.push(curr->left);
//         if (curr->right) q.push(curr->right);
//     }
// }
// }
//
// int height(node* root) {
//     if (root==nullptr) return 0;
//     int count=1;
//     queue<node*>q;
//     if (root->data)q.push(root);
//     q.push(nullptr);
//     while (!q.empty()) {
//         node* curr=q.front();
//         q.pop();
//         if (curr==nullptr) {
//             if (q.empty())break;
//             q.push(nullptr);
//             count++;
//         } else {
//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         }
//     }
//     return count;
// }
//
// int heightt(node* root) {
//     if (root==nullptr)return 0;
//     return max(heightt(root->left),heightt(root->right))+1;
// }

int main() {
//     vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
//     node* root=buildTrees(nodes);
// preorder(root);
//     cout<<endl;
//     bfs(root);
//     cout<<endl;
//     cout<<height(root);
    // cout<<heightt(root);

string a="ABAB";
    string b="AB";
    cout<<a % b;
    return 0;
}
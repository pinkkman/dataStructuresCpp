#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class node{
    public:
unordered_map<char,node*>children;
bool endofword;
int freq;
node(){
endofword=false;
}
};

class trie{
public:
node* root;
trie(){
    root=new node();
    root->freq=-1;
}


void insert(string key){
node* temp =root;
for(int i=0;i<key.size();i++){

if(temp->children.count(key[i])==0){ //character absent 
temp->children[key[i]]=new node();  //insert krdo
temp->children[key[i]]->freq=1;
}else{
    temp->children[key[i]]->freq++;
}

temp=temp->children[key[i]]; //niche chle jao next time ke lie
}
temp->endofword=true;
}

bool search(string key){
    node* temp=root;
    for(int i=0;i<key.size();i++){
if(temp->children.count(key[i])==0)return false;
else temp=temp->children[key[i]];
    }
return temp->endofword;
}

string getprefix(string key){
node* temp=root;
string ans="";
for(int i=0;i<key.size();i++){
    ans+=key[i];
    if(temp->children[key[i]]->freq==1){ // mtlb single branch
break;
    }
    temp=temp->children[key[i]];
}
return ans;
}
};

void prefix(vector<string>words){
    trie trie;
    for(int i=0;i<words.size();i++){
trie.insert(words[i]);   //insert me changes hai frequency track krrhe hai
    }
for(int i=0;i<words.size();i++){
    cout<<trie.getprefix(words[i])<<endl;
}
}



int main(){
 
    vector<string>words={"zebra","dog","duck","dove"};
prefix(words);
    return 0;
}

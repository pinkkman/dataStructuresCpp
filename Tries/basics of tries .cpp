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
node(){
endofword=false;
}
};

class trie{
public:
node* root;
trie(){
    root=new node();
}


void insert(string key){
node* temp =root;
for(int i=0;i<key.size();i++){

if(temp->children.count(key[i])==0){ //character absent 
temp->children[key[i]]=new node();  //insert krdo
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


};


int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    trie trie;

    for(int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    cout << trie.search("th") << endl; // 1
    return 0;
}

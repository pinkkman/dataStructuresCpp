#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;
//queue
// first non repeating char

void fnrc(string str){
queue<char>q;
int freq[26]={0};
for(int i=0;i<str.size();i++){
char ch=str[i];
 q.push(ch);
freq[ch-'a']++; //to access the index by ascii
  //filling the freq array

while(!q.empty() && freq[q.front()-'a']>1){  //removing the unnecessary repeated elemts
q.pop();
}
if(q.empty()){        //jo nahi bacha wo repeated element popped
  cout<<"-1";
}else{
  cout<<q.front();   //jo bach gya wo answer 
}
}
}


int main(){
string str="askfofsak";
fnrc(str);

  return 0;
}
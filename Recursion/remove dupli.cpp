#include<iostream>
#include<vector>
using namespace std;
//string recusion //passing i=0
string rd(string s,string ans,int i,bool map[]){
    if(s[i]=='\0') return ans;   //basecase

if(map[s[i]]==false){   //kaam
   ans+=s[i];
   map[s[i]]=true;
    }
return rd(s,ans,i+1,map);  // rec call
}

int main(){ 
    // these are essential parameters 
    string ans="";
    string s="appnnacollege";
    bool map[26]={false};      // all index are filled with false to check

    cout<<rd(s,ans,0,map);
    return 0;
}

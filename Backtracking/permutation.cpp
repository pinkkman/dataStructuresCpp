#include<iostream>
#include<vector>
#include<string>
using namespace std;

void per(string str,string ans){
    int n=str.size();
if(str.size()==0){    //BC when all chars removed from str and added to ans
cout<<ans<<endl;
return;
}
for(int i=0;i<n;i++){
char a=str[i];
string nextstr=str.substr(0,i) + str.substr(i+1,n-i-1);  //removing ith char and adding it to ans
per(nextstr,ans+a);
}

}
int main(){
string str="abc";
string ans="";

per(str,ans);
    return 0;
}
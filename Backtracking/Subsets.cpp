#include<iostream>
#include<vector>
#include<string>
using namespace std;

void ss(string str,string subset){
    if(str.size()==0){ 
        cout<<subset<<endl;  //BC
        return;}
    char ch=str[0];

    ss(str.substr(1,str.size()-1),subset+ch);  //yes
    ss(str.substr(1,str.size()-1),subset);  //no
}


int main(){
string str="abc";
string subset="";

ss(str,subset);
    return 0;
}
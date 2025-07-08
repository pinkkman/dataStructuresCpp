#include<iostream>
#include <climits>
#include<vector>
#include <cstring>
#include <string>
using namespace std;
//dynamic 2d array

string ith(int n,int i){
 int a=(~(1));
 if(n==(n&a)){
    return "Yes";
 }else{
    return "No";
 }
}

int main(){
 int n,i;
 cin>>n;
cout<<ith(n,i);
    return 0;
}
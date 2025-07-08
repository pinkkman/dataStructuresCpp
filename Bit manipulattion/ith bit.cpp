#include<iostream>
#include <climits>
#include<vector>
#include <cstring>
#include <string>
using namespace std;
//dynamic 2d array

int ith(int n,int i){
int a=1<<i;
if((n&a)==0){
    return 0;
}else{
    return 1;
}

}

int main(){
 int n,i;
 cin>>n>>i;
cout<<ith(n,i);
    return 0;
}
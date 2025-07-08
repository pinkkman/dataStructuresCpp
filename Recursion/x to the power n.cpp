#include<iostream>
#include<vector>
using namespace std;

int exp(int x ,int n){
if(n==1) return x;

    return x*exp(x,n-1);
}

int main(){
cout<<exp(2,4);
    return 0;
}

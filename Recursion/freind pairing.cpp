#include<iostream>
#include<vector>
using namespace std;
int fp(int n){
if(n==2 || n==1){ return n;}

    return fp(n-1) + (n-1)*fp(n-2);
}

int main(){ 
int n=4;
cout<<fp(n);

    return 0;
}

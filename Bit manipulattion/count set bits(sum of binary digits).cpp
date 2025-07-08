#include<iostream>
#include <climits>
#include<vector>
#include <cstring>
#include <string>
using namespace std;
//dynamic 2d array

int ith(int n){
int pow=1,sum=0,b=0;
while(n>0){
    int rem=n%2;
     b+=rem*pow;
     n/=2;
     pow*=10;
}
while(b>0){
sum+=b%10;
b/=10;
}
return sum;
}

int main(){
 int n,i;
 cin>>n;
cout<<ith(n);
    return 0;
}
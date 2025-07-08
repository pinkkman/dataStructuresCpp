#include<iostream>
#include<vector>
using namespace std;
//ugh seems like fibonacci 
int tp(int n){
if(n==0) return 1;
if(n==1) return 1;
// verical ways
int ans1=tp(n-1);  //2 x n-1
    
//horizontal ways 
int ans2=tp(n-2); // 2 x n-2

return ans1+ans2;
}
int main(){
cout<<tp(7);
    return 0;
}

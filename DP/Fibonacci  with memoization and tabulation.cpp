#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
using namespace std;


int fib0(int n) {   //o(n^2)
    if (n==0 || n==1) return n;
return fib0(n-1)+ fib0(n-2 );

}
void fib(int n,int prev=0,int curr=1,int idx=1) { //O(n)

    if (idx==n)return;
    cout<<curr<<"   ";
    fib(n,curr,prev+curr,idx+1);
}

int fibDP(int  n , vector<int>dp) { //O(n)
    if(n==1 || n==0)return n;

if (dp[n]!=-1) {
    return dp[n];
}

    return dp[n]=fibDP(n-1,dp)+fibDP(n-2,dp);
}

int fibTAB(int n) {
vector<int>f(0,n+1); // ith -> fib[i]    //step 1
    f[0]=0;    //init with smallest solution  ///step 2
    f[1]=1;

    for (int i=2;i<=n;i++) f[i] = f[i-1] + f[i-2];   // solve small to large   //step 3
return f[n];
}

int main() {
int n=10;
    cout<<0<<"   ";
 fib(n);

cout<<endl;
cout<<fib0(n)<<endl;
    vector<int>dp(n+1,-1);
cout<<fibDP(n,dp);


    return 0;
}
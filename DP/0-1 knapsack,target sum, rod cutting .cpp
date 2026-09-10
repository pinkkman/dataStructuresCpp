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

int knapsackRec(vector<int>val,vector<int>wt,int W, int n) { // O(2^n)

    if (wt[n-1]==0 || n==0)return 0; // BC

     int itemVal=val[n-1];
     int itemWt=wt[n-1];

    if (itemWt <= W) { //include
        //include
int ans1=knapsackRec(val,wt,W-itemWt,n-1) + itemVal;

        //exclude
        int ans2=knapsackRec(val,wt,W,n-1);

        return max(ans1,ans2);
    }else {  //exclude
return knapsackRec(val,wt,W,n-1);

    }
}


int knapsackRecMem(vector<int>val,vector<int>wt,vector<vector<int>>&dp,int W, int n) {   // O(n*W)

    if (wt[n-1]==0 || n==0)return 0; // BC
if (dp[n][W] != -1) return dp[n][W];

    int itemVal=val[n-1];
    int itemWt=wt[n-1];

    if (itemWt <= W) { //include
        //include
        int ans1=knapsackRecMem(val,wt,dp,W-itemWt,n-1) + itemVal;

        //exclude
        int ans2=knapsackRecMem(val,wt,dp,W,n-1);

        dp[n][W]= max(ans1,ans2);
    }else {  //exclude
        dp[n][W]= knapsackRecMem(val,wt,dp,W,n-1);
    }

    return dp[n][W];
}

int knapsackRecTab(vector<int>val,vector<int>wt,int W, int n) {
vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=W;j++) {
            int itemWt=wt[i-1];
            int itemVal=val[i-1];
          if (itemWt<=j) {  //include
              dp[i][j]=max(dp[i][j-itemWt] + itemVal , dp[i-1][j]);
              //  unbounded  dp[i][j-itemWt]
          }else {  //exclude
              dp[i][j]=dp[i-1][j];
          }

        }
    }

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=W;j++) {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
return dp[n][W];
}


bool targetSum(vector<int>nums,int target) {
int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
for (int i=1;i<=n;i++) {
    for (int j=1;j<=target;j++) {
        if (nums[i-1] <= j) {
            dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]] , dp[i-1][j] );
        }else {
            dp[i][j]=dp[i-1][j];
        }
    }
}
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=target;j++) {
            cout<<dp[i][j]<<"       ";
        }cout<<endl;
    }
return dp[n][target]==target;
}


int rodCutting(vector<int>price,vector<int>length,int rl) {
    int n=length.size();
vector<vector<int>>dp(n+1,vector<int>(rl+1,0));
for (int i=0;i<=n;i++) dp[i][0]=0;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=rl;j++) {
            if (length[i-1]<=j) {
                dp[i][j]=max(dp[i][j-length[i-1]] +price[i-1], dp[i-1][j]);
            }else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=rl;j++) {
                    cout<<dp[i][j]<<"  ";
        }cout<<endl;
            }
return dp[n][rl];
}

int main() {
vector<int>val={15,45,10,14,30};
    vector<int>wt={2,3,1,5,4};
    int n=val.size();
    int W=7;
// cout<<knapsackRec(val,wt,W,n)<<endl;
//
//     vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
// cout<<knapsackRecMem(val,wt,dp,W,n)<<endl;
//
//     for (int i=0;i<=n;i++) {
//         for (int j=0;j<=W;j++) {
//             cout<<dp[i][j]<<"  ";
//         }cout<<endl;
//     }
//
//     cout<<endl<<endl;
//     cout<<knapsackRecTab(val,wt,W,n);
// //
// vector<int>nums={4,2,7,1,3};
// if (targetSum(nums,14)) cout<<"true";
//     else cout<<"false";

cout<<rodCutting({1,5,8,9,10,17,17,20},{1,2,3,4,5,6,7,8},8);

    return 0;
}
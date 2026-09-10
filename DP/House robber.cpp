class Solution {  // tabulation
public:
    int rob(vector<int>& arr) {
  
    int n=arr.size();
      vector<int>dp(n);

if(n==1)return arr[0];

dp[0]=arr[0];
dp[1]=max(arr[1],arr[0]);
for(int i=2;i<n;i++){
dp[i]=max(dp[i-1],dp[i-2]+arr[i]);

}

        return dp[n-1];
    }
};


class Solution {   //memoization
public:

int solve(vector<int>arr,int i,vector<int>&dp){ 
        int n=arr.size();
    if(i<0) return 0;
    
    if(dp[i] != -1) return dp[i];

return dp[i]=max( solve(arr,i-1,dp) , solve(arr,i-2,dp) + arr[i] );
}
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
return solve(arr,n-1,dp);
    }

};



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
#include<set>
#include<list>
#include<cmath>
using namespace std;

int lcsRec(string str1,string str2) {
int n=str1.size();
    int m=str2.size();

if (n==0 || m==0) return 0;

    if (str1[n-1]==str2[m-1]) {
        return 1+ lcsRec(str1.substr(0,n-1),str2.substr(0,m-1));
    } else {
        int ans1=lcsRec(str1.substr(0,n-1),str2);
        int ans2=lcsRec(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
    }

}

string lcsRec2(string str1,string str2) {
    int n=str1.size();
    int m=str2.size();

    if (n==0 || m==0) return "";

    if (str1[n-1]==str2[m-1]) {
        return str1[n-1] + lcsRec2(str1.substr(0,n-1),str2.substr(0,m-1));
    } else {
        string ans1=lcsRec2(str1.substr(0,n-1),str2);
        string ans2=lcsRec2(str1,str2.substr(0,m-1));
       if (ans1.size()>ans2.size()) return ans1;
        else return ans2;
    }

}
int lcsMemo(string str1,string str2,vector<vector<int>>&dp) {
    int n=str1.size();
    int m=str2.size();
if (m==0 || n==0) return 0;

    if (dp[n][m]!=-1) return dp[n][m];

    if (str1[n-1]==str2[m-1]) {
        dp[n][m]=1+ lcsMemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else {
        dp[n][m]=max(lcsMemo(str1.substr(0,n-1),str2,dp),
            lcsMemo(str2.substr(0,m-1),str1,dp));
    }
return dp[n][m];
}

int lcsTab(string str1,string str2) {

    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1 ,vector<int>(m+1,0));

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (str1[i-1]==str2[j-1]) {
                dp[i][j]= 1 + dp[i-1][j-1];
            }else {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            cout<<dp[i][j]<<"  ";

        }cout<<endl;
    }

    return dp[n][m];

}

int lcSubTab(string str1,string str2) {
int ans =0;
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
        if (str1[i-1]==str2[j-1]) {
dp[i][j]=1+dp[i-1][j-1];

        }else { // ab , abd ,, -> b!=d hence store 0
            dp[i][j]=0;
        }
         ans=max(dp[i][j],ans);
    }
}
return ans;
}

int lisTab(vector<int>v1,vector<int>v2) {

    int n=v1.size();
    int m=v2.size();
    vector<vector<int>>dp(n+1 ,vector<int>(m+1,0));

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (v1[i-1]==v2[j-1]) {
                dp[i][j]= 1 + dp[i-1][j-1];
            }else {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            cout<<dp[i][j]<<"  ";

        }cout<<endl;
    }

    return dp[n][m];

}

int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    //1 +
    //insert - dp[i][j-1]
    //delete - dp[i-1][j]
    //replace- dp[i-1][j-1]
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]= 0 + dp[i-1][j-1];   //no operations done
            }else{
                dp[i][j]= 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}); // insert or delete or replace respectively
            }
        }
    }

    return dp[n][m];
}


int main() {
// string a="abcde";
//     string b="abgcde";
//     cout<<lcsRec(a,b)<<endl;
//  string ans=lcsRec2(a,b);
//     reverse(ans.begin(),ans.end());
//     cout<<ans<<endl;
//
//     vector<vector<int>>dp(a.size()+1 ,vector<int>(b.size()+1,-1));
//
// cout<<lcsMemo(a,b,dp)<<endl;
// for (int i=0;i<=a.size();i++) {
//     for (int j=0;j<=b.size();j++) {
//         cout<<dp[i][j]<<"  ";
//
//     }cout<<endl;
// }
//     cout<<lcsTab(a,b)<<endl;
//     cout<<lcSubTab(a,b);
    vector<int>v={50,3,10,7,40,80};
    set<int>s;
    for (int x:v)s.insert(x);
    vector<int>v2;
for (int x:s)v2.push_back(x);

    cout<<lisTab(v,v2);

    return 0;
}
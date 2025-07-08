#include<iostream>
#include <climits>
#include<vector>
using namespace std;

int staircase(int arr[][3],int m,int n,int t){
int ans,i=0, r=0,c=n-1;
   while(i<m*n){

   ans=arr[r][c];
   if(ans==t){
    return  r*10+c;
   }else if(ans>t){
c--;
   }else{
    r++;
   }i++;

   }
return -1;
}
int main(){
const int m=4,n=3;
int arr[m][n];
int t=8;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}

cout<<staircase(arr,m,n,t);
    return 0;
}
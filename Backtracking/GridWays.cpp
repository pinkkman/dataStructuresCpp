#include<iostream>
#include<vector>
#include<string>
using namespace std;
//grid ways with right and down

int ways(int r,int c, int m,int n,string ans){
     if(r==m-1 && c==n-1) {
        cout<<ans<<endl;
        return 1;  }  //BC 

    if(r>=m || c>=n) return 0;
    
    int v1=ways(r,c+1,m,n,ans+'R'); //right ways
    int v2=ways(r+1,c,m,n,ans+'D'); //down ways
    int v=v1+v2;
    return v;

}

int main(){
int m=3,n=3;
cout<<ways(0,0,m,n,"");
    return 0;
}
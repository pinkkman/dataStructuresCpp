#include<iostream>
#include <climits>
#include<vector>
using namespace std;

void spiral(int arr[][3],int m,int n){
    int s=0,er=n-1,i=0;
    int ec=m-1;
while(s <= ec && s <= er){

    for(int j=s;j<=er;j++){  //top
        cout<<arr[s][j]<<" ";
        i++;
    }
    for(int j=s+1;j<=er;j++){  //right
        cout<<arr[j][er]<<" ";
        i++;
    }

    for(int j=ec-1;j>=s;j--){  //bottom
        cout<<arr[ec][j]<<" ";
        i++;
    }
     for(int j=ec-1;j>s;j--){  //left
        cout<<arr[j][s]<<" ";
        i++;
    }
s++,er--,ec--;
}
}
int main(){
const int m=4,n=3;
int arr[m][n];
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
spiral(arr,m,n);
    return 0;
}
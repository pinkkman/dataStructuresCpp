#include<iostream>
#include<vector>
using namespace std;

int rs(int arr[],int st,int en,int t){
    if (st > en) return -1;
    int mid=(st+en)/2;
    if (arr[mid]==t) return mid;
if(arr[st]>=arr[mid]){  // right part sorted
 if( t>arr[mid] &&t<=arr[en]){     //check right
    rs(arr,mid+1,en,t);
 } else{            //check left
    rs(arr,st,mid-1,t);
 }
}

else{               // left part sorted
if(t<=arr[mid] && t>arr[st]){    //check left 
rs(arr,st,mid-1,t);
}else{             //check right
rs(arr,mid+1,en,t);
}
}
}

int main(){
int arr[]={6,7,8,0,1,4};
int n=6;
cout<<rs(arr,0,n-1,1);

    return 0;
}
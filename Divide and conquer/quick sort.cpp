#include<iostream>
#include<vector>
using namespace std;

int part(int arr[],int st,int en){
int i=st-1;
int piv=arr[en];
for(int j=st;j<en;j++){
    if(arr[j]<=piv){
        swap(arr[++i],arr[j]);
    }
}

swap(arr[i+1],arr[en]);
return i+1;
}

void qs(int arr[],int st,int en){
    if(st>=en) return ;
int piv=part(arr,st,en);
qs(arr,st,piv-1);
qs(arr,piv+1,en);

}


int main(){
int arr[]={3,7,1,0,4,5};
int n=6;
qs(arr,0,n-1);
for(int i=0;i<n;i++){
cout<<arr[i]<<endl;
}
    return 0;
}
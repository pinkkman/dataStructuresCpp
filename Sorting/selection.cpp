#include<iostream>
#include <climits>
#include<vector>
using namespace std;

void ss(int arr[],int n){
for(int i=0;i<n;i++){
int mi=i;
for(int j=i+1;j<n;j++){
    if(arr[mi]>arr[j]){
        mi=j;
    }
}swap(arr[mi],arr[i]);

}

}

int main(){
int arr[]={7,6,3,5,4};
ss(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}
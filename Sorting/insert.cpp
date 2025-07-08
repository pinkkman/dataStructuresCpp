#include<iostream>
#include <climits>
#include<vector>
using namespace std;
//think of it as sorting cards in hand

void is(int arr[],int n){
for(int i=1;i<n;i++){  
int curr=arr[i];
int prev=i-1;
while(prev>=0 && arr[prev]>curr){  
    swap(arr[prev],arr[prev+1]);
    prev--;
}
}

}

int main(){
int arr[]={7,6,3,5,4};
is(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}
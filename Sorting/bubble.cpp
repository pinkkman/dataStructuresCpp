#include<iostream>
#include <climits>
#include<vector>
using namespace std;

void bs(int arr[],int n){
for(int i=0;i<n;i++){
bool isswap=false;
    for(int j=0;j<n-i;j++){
if(arr[j]>arr[j+1]){
    swap(arr[j],arr[j+1]);
    isswap=true;
}
if (isswap==false){return ;}
    }
}
}

int main(){
int arr[]={7,6,3,5,4};
bs(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}
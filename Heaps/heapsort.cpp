#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

void heapify(int i,vector<int>&arr,int n){
int l=2*i + 1;
int r=2*i + 2;
int mx=i;
if(l<n && arr[l]>arr[mx]){
    mx=l;
}
if(r<n && arr[r]>arr[mx]){
    mx=r; 
}
swap(arr[mx],arr[i]);
if(mx!=i){
    heapify(mx,arr,n);
}
}

void heapsort(vector<int>&arr){
    int n=arr.size();
    //converting into max heap
    for(int i=n/2 - 1;i>=0;i--){
    heapify(i,arr,n);
    }
//fixing or moving the highest
for(int i=n-1;i>=0;i--){
 swap(arr[0],arr[i]);
 heapify(0,arr,i);   
}

}

int main() {
vector<int>arr={1,4,2,5,3};
heapsort(arr);
for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
}
    return 0;
}

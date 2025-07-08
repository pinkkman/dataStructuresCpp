#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int st,int mid,int en){
vector<int>temp;
int i=st;
int j=mid+1;
while(i<=mid && j<=en){
    if (arr[i] <= arr[j]) {
        temp.push_back(arr[i++]);
    } else {
        temp.push_back(arr[j++]);
    }
}

//remaining elements to be pushed
while(i<=mid){  
    temp.push_back(arr[i++]);   
}
while(j<=en){
    temp.push_back(arr[j++]);
}

//copying to original array
for(int idx=st,x=0;idx<=en;idx++){  //starting from st because it can be any smaller subb array(divided arr)
    arr[idx]=temp[x++];
}
}


void ms(int arr[],int st,int en){
if(st>=en) return;

    int mid= st + (en-st)/2;
    ms(arr,st,mid); //left half
    ms(arr,mid+1,en); //right half
merge(arr,st,mid,en);
}

void print(int arr[],int n){
for(int i=0;i<n;i++){
    cout<<arr[i];
}
}

int main(){ 
int arr[5]={4,2,8,0,2};
int n=5;
ms(arr,0,n-1);
print(arr,n);
    return 0;
}

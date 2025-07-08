#include<iostream>
using namespace std;

int sorted(int arr[],int s){
if(s==1) {
    cout<<"sorted";
    return 0;}

if(arr[s-1]>arr[s-2] || arr[s-1]==arr[s-2]){
    return sorted(arr,s-1);
}else{
    cout<<"Not sorted";
    return 0;
}
}

int main(){
int arr[]={2,2,4,4,5};
sorted(arr,5);

    return 0;
}

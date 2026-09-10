#include<iostream>
using namespace std;

int bins(int arr[],int tar){

    int st=0,end=sizeof(arr)-1;
    int mid;

    while(st<end){
        mid=(st+end)/2;
        if(tar==mid){
            return mid;
        }else if(tar>mid){
st=mid;
        }else{
            end=mid;
        }
    }return mid;
        
}

int main(){
int arr[]={2,3,4,7,8,10};
int tar=7;
cout<<bins(arr,tar);
    return 0;
}
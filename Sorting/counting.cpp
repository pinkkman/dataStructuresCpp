#include<iostream>
#include <climits>
#include<vector>
using namespace std;
void cs(int arr[],int n){
int freq[10000]={0};
int mn=INT_MAX,mx=INT_MIN;
for(int i=0;i<n;i++){   //range
mn=min(mn,arr[i]);
mx=max(mx,arr[i]);
}

for(int i=0;i<n;i++){
freq[arr[i]]++;
}


for(int i=mn,j=0;i<=mx;i++){
    while(freq[i]>0){
        arr[j]=i;
        freq[i]--;
        j++;
    }

}
}


int main(){
int arr[]={7,6,5,7,4};
cs(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}
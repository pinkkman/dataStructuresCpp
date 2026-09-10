#include <iostream>
#include<vector>
using namespace std;
 
 int bins(vector<int>arr,int tar){
int n=arr.size();
int st=0,end=n-1,ans;
for(int i=st;i<=end;i++){
  int mid=st - (st+end)/2;
  //  if(arr[st]==tar){
  //   ans=st;
  // }
  //  else if(arr[end]==tar){
  //   ans=end;}
   if(arr[mid]<tar){
    st=mid+1;
  }
  else if(arr[mid]>tar){
    end=mid-1;
  }
  else {
    ans=mid;
    }
}return ans;

 }


int main()
{
vector<int>arr={2,4,5,9,13};
int tar=13;
cout<<bins(arr,tar);

  return 0;
}
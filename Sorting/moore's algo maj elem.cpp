#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& arr) {
    int n = arr.size();  
  int count=1;
int a=arr[0];
       for(int i=1;i<n;i++){
       if(arr[i]==a){
        count++;
       }else{
        count--;
       }
if(count==0){
  a=arr[i];
  count=1;
}
}
count=0;
for(int i=0;i<n;i++){
  if(arr[i]==a){
    count++;
  }
}

if(count>n/2){
  return a;
}else{
  return -1;
}
}
int main() {
    vector<int> arr = {1, 2, 2, 3, 2, 1};
    
    cout << majorityElement(arr) << endl;

    return 0;
}
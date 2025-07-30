#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<int> majorel(vector<int>arr){
unordered_map<int,int>m; //arr[i],freq 
int n=arr.size();
vector<int>ans;
for(int i=0;i<n;i++){
    if(m.count(arr[i])){  //if exists
m[arr[i]]++;
    }else{  //if not
m[arr[i]]=1;
    }
}

for( pair<int,int>it :m){
if(it.second>n/3){
 ans.push_back(it.first);   
}
}return ans;
}

bool valanagram(string s,string t){
unordered_map<char,int>m;
for(int i=0;i<s.size();i++){
    m[s[i]]++;
}
if(s.size()!=t.size())return false;
for(int i=0;i<t.size();i++){
if(m[t[i]]){// if exists
m[t[i]]--;

if(m[t[i]]==0) m.erase(t[i]);
}else{ //donot exists invalid
return false;
}
}
if(m.size()==0)return true;
else return false;
}

int countdis(vector<int>arr){
    int count=0;
unordered_map<int,int>m; //arr[i],freq
for(int i=0;i<arr.size();i++){
m[arr[i]]++;
}
for(pair<int,int>it: m){
if(it.second==1){
count++;
}
}return count;
}

void unionn(vector<int>arr1,vector<int>arr2){
unordered_set<int>s;
for(int i=0;i<arr1.size();i++){
    s.insert(arr1[i]);
}
for(int i=0;i<arr2.size();i++){
    s.insert(arr2[i]);
}
for(int it:s){
    cout<<it<<"  ";
}
}

vector<int> intersection(vector<int>arr1,vector<int>arr2){
unordered_set<int>s;
vector<int>ans;
for(int i=0;i<arr1.size();i++){
    s.insert(arr1[i]);
}
for(int i=0;i<arr2.size();i++){
if(s.find(arr2[i])!=s.end()){// found !!
ans.push_back(arr2[i]);
s.erase(arr2[i]);
}
}
return ans;
}

void ticketplan(unordered_map<string, string> tickets){
unordered_set<string>to;
for(pair<string,string>it:tickets){
    to.insert(it.second);
}
string start="";
for(pair<string,string>it:tickets){
 if(to.find(it.first)==to.end()){ //not found in to means this is start 
start=it.first;
break;
    }
}
cout<<start<<" -> ";
while(tickets.count(start)){
    cout<<tickets[start]<<" -> ";
    start=tickets[start];
}
cout<<"destination";
}

int largestsumzerolenght(vector<int>arr){ //O(n)
unordered_map<int,int>m; //sum,idx
int sum=0;
int ans=0;
m[0]=-1;    //edge case
for(int i=0;i<arr.size();i++){
sum+=arr[i];
if(m.count(sum)){
    int currl=i-m[sum];  
    ans=max(ans,currl);
}else{
    m[sum]=i;
}
}
return ans;
}

//#IMP->  sum[i-j]=sum[j]-sum[i]

int largestsumkcount(vector<int>arr,int k){ 
unordered_map<int,int>m; //sum,count
int sum=0;
m[0]=1;  //edge case
int count=0;
for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    if(m.count(sum-k)){
        count+=m[sum-k];
    }
    m[sum]++;
}

}

int main(){
//     vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
//     vector<int> nums2 = {1, 2};

// vector<int>ans=majorel(nums2);
// for(int i : ans){
// cout<<i<<"  ";
// }

// string s="race";
// string t="eace";
// if(valanagram(s,t)) cout<<"valid ";
// else cout<<"invalid";

// vector<int>arr={4,3,2,5,6,7,3,4,2,1};
// cout<<countdis(arr);

//  vector<int> arr1 = {7, 3, 9};
//     vector<int> arr2 = {6, 3, 9, 2, 9, 4};
// unionn(arr1,arr2);
// cout<<endl;
// vector<int>ans=intersection(arr1,arr2);
// for(int it:ans){
//     cout<<it<<"  ";
// }


//     unordered_map<string, string> tickets;
//     tickets["Chennai"] = "Bengaluru";
//     tickets["Mumbai"] = "Delhi";
//     tickets["Goa"] = "Chennai";
//     tickets["Delhi"] = "Goa";
// ticketplan(tickets);

// vector<int>arr={15,-2,2,-8,1,7,10};
// cout<<largestsumzerolenght(arr);

// cout<<largestsumkcount(arr);

    return 0;

}
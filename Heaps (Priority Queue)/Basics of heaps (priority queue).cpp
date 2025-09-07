#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;


class Heap{
public:
vector<int>vec;

void push(int val){  //max value ko uper tak lana hai
vec.push_back(val);
int n=vec.size();
int x=n-1;
int pidx=(x-1)/2;
    //child   parent
while(vec[x]>vec[pidx] && pidx>=0){
swap(vec[x],vec[pidx]);
x=pidx;
pidx=(x-1)/2;
}
}

void heapify(int i){ ///i=parent index
int l= 2*i + 1;      ///l=leftchild
int r= 2*i + 2;      ///r=rightchild
int mx=i;
//finding max val from l r and parent
if(l<vec.size() && vec[l]>vec[mx]){ //if l is valid 
mx=l;
}
if(r<vec.size() && vec[r]>vec[mx]){
mx=r;
}
swap(vec[mx],vec[i]);
if(mx!=i){ //agar swapping hua hai to aur kro wrna return
    heapify(mx);
}
return;
}

void pop(){  //minimum ko bottom tk lana hai
swap(vec[0],vec[vec.size()-1]);
vec.pop_back();
if(vec.size()==0)return; //agar 1 element hoga only root then return
heapify(0);

}

int top(){
return vec[0];
}

bool empty(){
    return vec.size()==0;
}
};

void pop(){
swap(vec[0],vec[vec.size()-1]);
vec.pop_back();
if(vec.size()==0)return; //agar 1 element hoga only root then return
heapify(0);

}

int top(){
return vec[0];
}

bool empty(){
    return vec.size()==0;
}
};


int main() {
Heap heap;
heap.push(20);
    cout<<heap.empty()<<endl;
    heap.pop();
     cout<<heap.empty()<<endl;
   
    return 0;
}

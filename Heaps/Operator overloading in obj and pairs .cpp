#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

class student{
public:
string name;
int marks;
student(string name,int marks){
this->name=name;
this->marks=marks;
}
//operator overloading::

bool operator < (const student &obj) const{
    return this->marks < obj.marks;    //max heap
    // return this->marks > obj.marks;    //max heap
}
};

struct compare{
    bool operator() (pair<string,int>&p1, pair<string,int>&p2){
      return  p1.first < p1.first; //max heap
    //   return  p2.first > p2.first; //min heap
    }
};

int main() {
//object
priority_queue<student>pq;
pq.push(student("rado",65));
pq.push(student("lalla",76));
pq.push(student("jacky",88));
   
while(!pq.empty()){
    cout<<"top -> "<<pq.top().name<<" : "<<pq.top().marks<<endl;
    pq.pop();
}

//pairs
priority_queue< pair<string,int> ,
vector< pair<string,int> > , 
compare
>pq;
pq.push(make_pair("rado",65));
pq.push(make_pair("lalla",76));
pq.push(make_pair("jacky",88));
   
while(!pq.empty()){
    cout<<"top -> "<<pq.top().first<<" : "<<pq.top().second<<endl;
    pq.pop();
}
    return 0;
}

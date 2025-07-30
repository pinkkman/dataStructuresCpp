#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

class car{
    public:
    int idx;
    int distsq;

    car(int idx,int distsq){
        this->idx=idx;
        this->distsq=distsq;
    }

    bool operator < (const car &obj) const {
return this->distsq > obj.distsq;  
    }
};

void nearbycars(vector<pair<int,int>>pos,int k){
vector<car>cars;
for(int i=0;i<pos.size();i++){ //O(n)
    int distsq=pos[i].first * pos[i].first + pos[i].second * pos[i].second;
    cars.push_back(car(i,distsq));
}

priority_queue<car>pq(cars.begin(),cars.end());   //O(n)
//agar loop lagate to nlogn lagta

for(int i=0;i<k;i++){
    cout<<pq.top().idx<<"  ";
    pq.pop();
}
}

void connectNropes(vector<int>ropes){
    int n=ropes.size();
    int cost=0;
    priority_queue<int,vector<int>,greater<int> >pq(ropes.begin(),ropes.end());  //O(n)
   while(pq.size()>1){
    int min1=pq.top();
    pq.pop();
    int min2=pq.top();
    pq.pop();
     cost+= min1 + min2;
     pq.push(min1+min2);
   }
    cout<<"min cost : "<<cost<<endl;
}

class row{
    public:
int count;
int idx;
row(int count,int idx){
this->count=count;
this->idx=idx;
}
bool operator < (const row &obj) const{   //first prior count hai wrna index
    if(this->count == obj.count){
        return this->idx > obj.idx;
    }
    return this->count > obj.count;
}

};

void weakestsoldier(vector<vector<int>>mat,int k){
    vector<row>rows;
    for(int i=0;i<mat.size();i++){
int count=0;
for(int j=0;j<mat[0].size() && mat[i][j]==1;j++){
count++;
    }
rows.push_back(row(count,i));
    }
    priority_queue<row>pq(rows.begin(),rows.end());
for(int i=0;i<k;i++){
    cout<<"Row : "<<pq.top().idx<<"  ";
}
}

int main(){
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));
    int k = 2;

   nearbycars(pos,k);

vector<int>ropes={4,3,2,6};
connectNropes(ropes);


    return 0;
}
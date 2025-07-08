#include<iostream>
#include <climits>
#include<vector>
#include <cstring>
#include <string>
using namespace std;
//dynamic 2d array

int main(){
    int r,c;
    cout<<"enter rows and columns : ";
    cin>>r>>c;
int* *matrix= new int *[r];
for(int i=0;i<r;i++){
    matrix[i]=new int[c];
}
//data
int x=1;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
*(*(matrix+i)+j)=x++;
cout<<*(*(matrix+i)+j);  //this is a way of input same as matrix[i][j];;
    }cout<<endl;
}


    return 0;
}
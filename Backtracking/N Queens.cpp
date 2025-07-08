#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool issafe(vector<vector<char>>board,int row,int col){
int n=board.size();
//horizontal safety
for(int i=0;i<n;i++){
    if(board[row][i]=='Q') return false;
}

//vertical safety
for(int i=0;i<n;i++){
    if(board[i][col]=='Q') return false;
}

//diagonal down right  safety 
for(int i=row,j=col;i<n&&j<n;i++,j++){
if(board[i][j]=='Q') return false;
}

//diaonal up left safety 
for(int i=row,j=col;i>=0&&j>=0;i--,j--){
if(board[i][j]=='Q') return false;
}

//diaonal down left safety 
for(int i=row,j=col;i<n&&j>=0;i++,j--){
    if(board[i][j]=='Q') return false;
}

//diaonal up right safety 
for(int i=row,j=col;i>=0&&j<n;i--,j++){
    if(board[i][j]=='Q') return false;
    }

//else true
return true;
}
void print(vector<vector<char>>board){
    int n=board.size();
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<board[i][j]<<"  ";
    }cout<<endl;
}cout<<"---------------"<<endl;
}

void nq(vector<vector<char>>board,int row){
int n=board.size();
    if(row==n){
        print(board);
        return;
    }
for(int j=0;j<n;j++){  //columns
if(issafe(board,row,j)){
    board[row][j]='Q';
nq(board,row+1);
board[row][j]='.';
}
}

}

int main(){
vector<vector<char>>board;
int n=4;
for(int i=0;i<n;i++){
vector<char>newrow;
for(int j=0;j<n;j++){
newrow.push_back('.');
}board.push_back(newrow);
}

nq(board,0);

    return 0;
}
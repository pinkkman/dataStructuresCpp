#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Sudoku solver//
void print(int sudoku[9][9]){
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cout<<sudoku[i][j]<<"  ";
    }cout<<endl;
}
}

bool issafe(int sudoku[9][9],int dig,int r,int c){
    //checking the column
for(int i=0;i<9;i++){  
    if(sudoku[i][c]==dig) return false;
}
    //checking the row
for(int i=0;i<9;i++){ 
    if(sudoku[r][i]==dig) return false;
}
    //searching the inner grid
 int sr=(r/3)*3;
 int sc=(c/3)*3;
    //checking the inner grid
    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(sudoku[i][j]==dig) return false;
        }
    }
    return true;
}


bool ss(int sudoku[9][9],int r,int c ){
    if(r == 9){
print(sudoku);
return true;
}
int nextr = r;
int nextc = c + 1;

if(c + 1 == 9) { // Move to next row if end of column
    nextr = r + 1;
    nextc = 0;
}
if(sudoku[r][c]!=0) {
   return ss(sudoku,nextr,nextc);
}

for(int dig=1;dig<=9;dig++){

if(issafe(sudoku,dig,r,c)){
sudoku[r][c]=dig;       //filling the appropriate digit
if(ss(sudoku, nextr, nextc)) return true; 
sudoku[r][c]=0;
}
}
return false;
}


int main(){
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    
ss(sudoku,0,0);

    return 0;
}
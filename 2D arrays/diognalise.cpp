#include<iostream>
#include<vector>
using namespace std;

// Function that returns elements of given mat in diagonal order
void diag(vector<vector<int>>&mat){
  int rows=mat.size();
  int cols=mat[0].size();
  int r,c;
  for(int i=0;i<rows;i++ ){
 r=i,c=0;
    while(r >= 0 && c < cols){
    cout<<mat[r][c]<<" ";
      r--;
      c++;
    }
}
  for(int i=1;i<cols;i++){
    r=rows-1,c=i;
    while(r>=0 && c<cols){
    cout<<mat[r][c]<<" ";
      r--;
      c++;
    }
  }
}


int main() {

    vector<vector<int>> mat = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 }
    };
  diag(mat);

    return 0;
}
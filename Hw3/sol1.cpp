#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <numeric>
using namespace std;
using namespace std::chrono;

void print_2D_vector(vector<vector<int>> const &v) {
  //helper function to print 2D vector
for (vector<int> row: v) {
    for (int val: row) {
      cout << val << " ";
}
    cout << '\n';
  }
}

vector<vector<int>> LCSHelper(string A,string B){
  int n=A.size();
  int m=B.size();
  vector<vector<int>> memo(n+1, vector<int>(m+1, 0));
  for (int i=0;i<n+1;i++){
    for (int j=0;j<m+1;j++){
      if ((i==0) or (j==0)){
        memo[i][j]=0;
      }
      else if (A[i-1]==B[j-1]){
        memo[i][j]=memo[i-1][j-1]+1;
      }
      else{
        memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
      }
    }
  }
  return memo;
}
string reconstruct(string A,string B,vector<vector<int>> memo){
  int n=A.size();
  int m=B.size();
  int row=n;
  int col=m;
  string LCS="";
  while(row>0 and col>0){
    if (A[row-1] == B[col-1]){
      LCS=A[row-1]+LCS;
      row=row-1;
      col=col-1;
    }else if (memo[row-1][col] > memo[row][col-1]){
      row=row-1;
    }else{
      col=col-1;
    }
  }
  return LCS;
}
void longestCommonSubsequence(string A,string B){
  vector<vector<int>> memo=LCSHelper(A,B);
  cout << "Length of LCS is : "<<memo[A.size()][B.size()]<<endl;
  string common_subseq=reconstruct(A,B,memo);
  cout << "LCS is : "<<common_subseq<<endl;
}

int main(int argc, char const *argv[]) {
  string C = "ABCDGH";
  string D = "AEDFHR";
  longestCommonSubsequence(C,D);
  return 0;
}

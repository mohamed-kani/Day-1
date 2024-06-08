#include<iostream>
#include<vector>
using namespace std;
/*  //Brute force Approach
void markRowzero(vector<vector<int>> &arr,int m,int i)
{
  for(int j=0;j<m;j++){
    if(arr[i][j]!=0)
      arr[i][j]=-1;
  }
}
void markColzero(vector<vector<int>> &arr,int n,int j){
  for(int i=0;i<n;i++){
    if(arr[i][j]!=0)
      arr[i][j]=-1;
  }
}
void setZeros(vector<vector<int>> &arr,int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==0)
      {
        markRowzero(arr,m,i);
        markColzero(arr,n,j);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==-1)
      {
        arr[i][j]=0;
      }
    }
  }
}
*/
/*  // Better Approach
void setZeros(vector<vector<int>> &arr,int n,int m){
  int row[n]={0},col[m]={0};
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++){
      if(arr[i][j]==0){
        row[i]=1;
        col[j]=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(row[i] || col[j]){
        arr[i][j]=0;
      }
    }
  }
}*/
void setZeros(vector<vector<int>> &arr,int n,int m){
  int col0=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==0){
        arr[i][0]=0;
        if(j!=0){
          arr[0][j]=0;
        }
        else{
          col0=0;
        }
      }
    }
  }
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++){
      if(arr[i][j]!=0){
        if(arr[0][j]==0 || arr[i][0]==0)
          arr[i][j]=0;
      }
    }
  }
  if(arr[0][0]==0){
    for(int j=0;j<m;j++)
      arr[0][j]=0;
  }
  if(col0==0){
    for(int i=0;i<n;i++)
      arr[i][0]=0;
  }
}
int main()
{
  int n;
  int m;
  cout<<"Enter row and column of 2-D matrix : ";
  cin>>n>>m;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++)
  {
    vector<int> a;
    cout<<i+1<<" row elements : \n";
    for(int j=0;j<m;j++){
      int num;
      cin>>num;
      a.push_back(num);
    }
    arr.push_back(a);
  }
  setZeros(arr,n,m);
  cout<<"After set Zeros: \n";
  for(auto it:arr){
    for(auto i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}

// Brute force take O(N*M)*(N+M) + O(N*M)
//Better Approach Take T.C : 2 * O(N*M) , S.C : O(N) + O(M)


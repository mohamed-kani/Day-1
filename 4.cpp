#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxSub(vector<int> &arr){
  int n=arr.size();
  int ansStart=-1,ansEnd=-1;
  int maxi =INT8_MIN;
  int Start;
  int sum=0;
  for(int i=0;i<n;i++){
    if(sum==0)  Start=i;
    sum+=arr[i];
    if(sum>maxi){
      maxi = sum;
      ansStart=Start;
      ansEnd = i;
    }
    if(sum<0) sum=0;
  }
  return maxi;
}
int main(){
  int n;
  cout<<"Enter num size : ";
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }
  cout<<"Maximum Subarry sum : "<<maxSub(arr);
  return 0;
}
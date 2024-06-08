#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void sortArray(vector<int> &arr){
  int low=0,mid=0,high = arr.size() - 1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[low],arr[mid]);
      low++;
      mid++;
    }
    else if(arr[mid]==1){
      mid++;
    }
    else{
      swap(arr[mid],arr[high]);
      high--;
    }
  }
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
  sortArray(arr);
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}
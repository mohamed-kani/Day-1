#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& arr){
  int profit=0,mini=arr[0],cost;
  for(auto it:arr){
    cost = it - mini ;
    profit = max(profit,cost);
    mini = min(it,mini);
  }
  return profit;
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
  cout<<"Maximum Profit : "<<maxProfit(arr);
  return 0;
}
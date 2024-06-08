#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nextPermute(vector<int> &num){
  int ind=-1;
  int n=num.size();
  for(int i=n-2;i>=0;i++){
    if(num[i]<num[i+1]){
      ind = i;
      break;
    }
  }
  if(ind==-1){
    reverse(num.begin(),num.end());
    return num;
  }
  for(int i=n-1;i>ind;i--){
    if(num[ind]<num[i]){
      swap(num[ind],num[i]);
      break;
    }
  }
  reverse(num.begin()+ind+1,num.end());
  return num;
}
int main(){
  int n;
  cout<<"Enter n value : ";
  cin>>n;
  cout<<"Enter number ; \n";
  vector<int> number;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    number.push_back(num);
  }
  nextPermute(number);
  for(auto it : number){
    cout<<it<<" ";
  }
  return 0;
}
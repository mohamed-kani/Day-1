#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void recurParam(vector<int> &ds,vector<int>& num,vector<vector<int>> &ans,int freq[]){
  if(ds.size()==num.size()){
    ans.push_back(ds);
    return;
  }
  for(int i=0;i<num.size();i++){
    if(!freq[i]){
      freq[i]=1;
      ds.push_back(num[i]);
      recurParam(ds,num,ans,freq);
      freq[i]=0;
      ds.pop_back();
    }
  }
}
vector<vector<int>> Permutate(vector<int>& num){
 vector<int> ds;
 int freq[num.size()]={0};
 vector<vector<int>> ans;
 recurParam(ds,num,ans,freq); 
 return ans;
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
  cout<<"Print all permutation : \n";
  vector<vector<int>> res=Permutate(arr);
  sort(res.begin(),res.end());
   for(auto it:res){
    for(auto i:it){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  cout << "Enter the current permutation: ";
    vector<int> current(n);
    for (int i = 0; i < n; i++) {
        cin >> current[i];
    }
  for (int i = 0; i < res.size(); i++) {
    if (res[i] == current) {
      if (i + 1 < res.size()) {
        cout << "Next permutation:\n";
        for (int num : res[i + 1]) {
          cout << num << " ";
        }
        cout << endl;
      } else {
        cout << "This is the last permutation " ;
      }
   }
  }
  return 0;
}
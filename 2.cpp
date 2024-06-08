#include<iostream>
#include<vector>
using namespace std;
int funNcr(int n,int r){
  int res=1;
  for(int i=0;i<r;i++){
    res = res * (n-i);
    res = res / (i+1);
  }
  return res;
}
vector<vector<int>> pascalTraingle(int n){
  vector<vector<int>> arr;
  for(int i=1;i<=n;i++)
  {
    vector<int> temp;
    for(int j=1;j<=i;j++){
      temp.push_back(funNcr(i-1,j-1));
    }
    arr.push_back(temp);
  }
  return arr;
}
vector<int> opt(int row){
  int ans=1;
  vector<int> ansPush;
  ansPush.push_back(ans);
    for(int i=1;i<row;i++){
    ans = ans*(row-i);
    ans = ans / i;
    ansPush.push_back(ans);
  }
  return ansPush;
}
vector<vector<int>> pascalTraingle1(int n){
  vector<vector<int>> arr;
  for(int i=1;i<=n;i++){
    arr.push_back(opt(i));
  }
  return arr;
}

int main(){
  int n,r;
  cout<<"enter n value : ";
  cin>>n;
  cout<<"enter r value : ";
  cin>>r;
  cout<<"Variation 1 \n";
  cout<<"Value is "<<funNcr(n-1,r-1);
  cout<<"\nVariation 2 \n";
  cout<<"Enter n values : ";
  cin>>n;
  /*for(int i=1;i<=n;i++) //O(n*r)
  {
    cout<<funNcr(n-1,i-1)<<" ";
  }*/
  int ans=1;
  cout<<ans<<" ";
  for(int i=1;i<n;i++){
    ans = ans*(n-i);
    ans = ans / i;
    cout<<ans<<" "; 
  }
  cout<<"\nVariation 3 : \n";
  cout<<"Enter n value : ";
  cin>>n;
  vector<vector<int>> arr = pascalTraingle(n);
  for(auto it:arr){
    for(auto i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  cout<<"Optimal approach\n";
  vector<vector<int>> arr1 = pascalTraingle1(n);
  for(auto it:arr1){
    for(auto i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
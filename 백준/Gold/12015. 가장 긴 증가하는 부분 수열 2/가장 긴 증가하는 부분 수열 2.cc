#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];
vector<int> result;

void input(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
}

int indexSearch(int x){
  int low = 0, hi = result.size()-1, mid;
  while(low<hi){
    mid = (hi+low)/2;

    if(result[mid] >= x){
      hi = mid;
    }else{
      low = mid+1;
    }
  }
  return hi;
}

void dp(){
  result.push_back(arr[0]);

  for(int i=1;i<n;i++){
    if(arr[i]>result.back()){
      result.push_back(arr[i]);
    }else{
      int index = indexSearch(arr[i]);
      result[index] = arr[i];
    }
  }
}

int main(){
  input();
  dp();
  cout<<result.size()<<"\n";
  return 0;
}

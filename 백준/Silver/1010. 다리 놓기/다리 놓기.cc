#include <iostream>
#include <vector>
using namespace std;

int N,M,d;
long long sum=1;
vector<int> result;
 bool visited[30];
void DP(int n,int q);
int DPV[30][30];

void input(){
  int T;
  cin>>T;
  for(int i=0;i<T;++i){
    cin>>N>>M;
    sum = 1;
    d=1;
    for(int i=M;i>M-N;--i){
      sum*=i;
      sum/=d;
      d++;
    }
    
    result.push_back(sum);
  }
  for(int i=0;i<result.size();++i)
    cout<<result[i]<<endl;
}


int main(){
  input();
  return 0;
}
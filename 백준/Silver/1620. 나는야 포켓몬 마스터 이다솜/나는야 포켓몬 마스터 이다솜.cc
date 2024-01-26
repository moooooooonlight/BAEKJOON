#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int n,m;
  string str;
  map<string, int> h;
  vector<string> name;
  vector<string> result; 

  cin>>n>>m;
  for(int i=1;i<=n;++i){
    cin>>str;
    name.push_back(str);
    h.insert({str,i});
  }





  
  for(int i=0;i<m;++i){
    cin>>str;
    if(str[0]>=65 && str[0]<=90){
      result.push_back(to_string(h[str]));
    }else{
      result.push_back(name[stoi(str)-1]);
    }
  }

  for (int i = 0; i < result.size();i++){
      cout << result[i] << '\n'; 
  }
  
  return 0;
}
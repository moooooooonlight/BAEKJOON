#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

int solution(string dartResult) {
  char dart[9];
  dartResult.copy(dart, dartResult.length()+1);
  int answer = 0;
  int arr[4]={0,};
  int x=0;
  for(int i=0;i<dartResult.size();++i){
      if(dart[i]>='0' && dart[i] <= '9'){
        if(dart[i]=='1' && dart[i+1]=='0'){
          x++;
          arr[x] = 10;
          i++;
        }else{
          x++;
          arr[x] = dart[i]-'0';
        }
      }else if(dart[i]=='S'){
          continue;
      }else if(dart[i]=='D'){
          arr[x] = pow(arr[x],2);
      }else if(dart[i]=='T'){
          arr[x] = pow(arr[x],3);
      }else if(dart[i]=='*'){
          if(x!=1) arr[x-1] *= 2;
        arr[x]*=2;
      }else if(dart[i]=='#'){
          arr[x] *= -1;
      }
    for(int i=1;i<4;++i){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
  answer = arr[1]+arr[2]+arr[3];
    return answer;
}
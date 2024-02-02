#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    long arr[n];
    for(int i=0;i<=n*2;++i){
        arr[i] = 0;
    }
    
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
   
    int x = s/n;
    
    for(int i=0;i<n;++i){
        answer.push_back(x);
    }
    
    int y = s%n;
    for(int i=n-1;i>n-1-y;--i){
        answer[i]++;
    }
    
    return answer;
}
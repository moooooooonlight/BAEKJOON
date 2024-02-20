#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> result;
    stack<int> s;
    for(int i=numbers.size()-1;i>=0;--i){
        if(s.empty()){
            result.push_back(-1);
            s.push(numbers[i]);
        }else {
            while(true){
                if(s.empty()){
                    result.push_back(-1);
                    s.push(numbers[i]);
                    break;
                }
                int x = s.top();
                if(numbers[i]>=x){
                    s.pop();
                }else{
                    result.push_back(x);
                    s.push(numbers[i]);
                    break;
                }
            }
        }
    }
    for(int i=result.size()-1;i>=0;--i){
        answer.push_back(result[i]);
    }
    return answer;
}
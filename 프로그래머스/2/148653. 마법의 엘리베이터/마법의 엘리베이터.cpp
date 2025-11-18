#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	
    int answer = 0;
    while(storey>0){
        if(storey%10>5 || (storey%10==5 && (storey%100)/10>=5)){
            answer+=10-storey%10;
            storey/=10;
            storey+=1;
        }else {
            answer += storey%10;
            storey/=10;
        }
    }
    
    
    return answer;
}
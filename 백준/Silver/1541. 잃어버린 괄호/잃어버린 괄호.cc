#include <stdio.h>
int main(){
    int n, sum=0;
    char c;
    scanf("%d",&n);
    sum+=n;
    
    while(1){
        scanf("%c",&c);
        if(c=='\n') break;
        if(c=='-'){
            while(1){
                scanf("%d",&n);
                sum-=n;
                scanf("%c",&c);
                if(c=='\n'){
                    printf("%d",sum);
                    return 0;
                }
            }
        }
        scanf("%d",&n);
        sum+=n;
    }
    printf("%d",sum);
    return 0;
}
#include <stdio.h>
void febonacci(int n){
    int arr[12];
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=n;++i){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    printf("%d\n",arr[n]);
}
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        febonacci(n);
    }
    return 0;
}
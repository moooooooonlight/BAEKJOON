#include <stdio.h>
int arr[101][3];
int dp[101][100001];

int max(int x,int y){
    if(x>y) return x;
    else return y;
}

int main(){
    
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d %d",&arr[i][1],&arr[i][2]);
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            if(j-arr[i][1]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i][1]]+arr[i][2]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
    
}

#include <iostream>
using namespace std;

int arr[100001];

int main(){
    int n,m;
    cin>>n>>m;
    int MAX=0, sum=0;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        if(MAX < arr[i])
            MAX = arr[i];
        sum+=arr[i];
    }
    int left = MAX; int right = sum;
    while(left<right){
        int mid = (left+right)/2;
        int x=0, y=mid;
        for(int i=1;i<=n;++i){
            if(y>arr[i]){
                y-=arr[i];
            }else{
                x++;
                y=mid;
                y-=arr[i];
            }
        }
        if(x<m){
            right = mid-1;
        }else left = mid+1;
    }
    cout<<left;
    return 0;
}


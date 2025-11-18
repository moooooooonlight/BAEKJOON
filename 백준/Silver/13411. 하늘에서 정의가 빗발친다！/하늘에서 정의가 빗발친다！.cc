#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
int x, y, v;
vector<pair<double,int>> result;


double cal(int a,int b,int z){
    return (double)sqrt(pow(a,2)+pow(b,2))/z;   
}

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>v;
        double V = cal(x,y,v);
        result.push_back({V,i});
    }
    sort(result.begin(),result.end());
}

void Print(){
    for(int i=0;i<n;i++){
        cout<<result[i].second<<"\n";
    }
}

int main(){
    input();
    Print();
    return 0;
}
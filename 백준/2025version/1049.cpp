#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    int groupMin = 1000, eachMin = 1000;
    cin >> n >> m;

    int g,e;
    for(int i=0;i<m;i++){
        cin >> g >> e;
        groupMin = min(groupMin, g);
        eachMin  = min(eachMin, e);
    }

    int temp1 = groupMin*(n / 6) + eachMin*(n % 6);
    int temp2 = groupMin*((n / 6) + 1);
    int temp3 = eachMin * n;

    int result = min({temp1, temp2, temp3});
    cout <<  result << endl;

    return 0;
}
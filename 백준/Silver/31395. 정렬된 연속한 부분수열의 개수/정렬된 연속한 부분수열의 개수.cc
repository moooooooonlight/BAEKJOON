#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  long sum = 0;
  long num = 0,x,y = 0;
  
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (y > x) { // 안되는 경우
      sum += (num * (num + 1)) / 2;
      num = 1;
    } else {
      num++;
    }
    y = x;
  }
  sum += (num * (num + 1)) / 2;
  cout << sum << endl;
  return 0;
}
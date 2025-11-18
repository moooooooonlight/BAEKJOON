#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long x, y;
  cin >> x;
  x %= m;
  for (int i = 0; i < n - 1; ++i) {
    cin >> y;
    y = y % m;
    x = (x * y) % m;
  }
  x %= m;
  cout << x;
  return 0;
}
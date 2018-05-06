#include <iostream>
using namespace std;


bool es_primer(int n) {
  if (n <= 1) return false;
  for (int d = 2; d*d <= n; ++d)
    if (n%d == 0) return false;
  return true;
}


int main() {
  int n;
  cin >> n;
  int x = 2;
  while (n) {
    if (es_primer(x)) {
      cout << x << endl;
      --n;
    }
    ++x;
  }
}

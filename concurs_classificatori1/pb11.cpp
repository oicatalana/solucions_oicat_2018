#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;


VE Q;


bool ok() {
  if (Q[0] > 1) return false;
  if (Q[1] > 2) return false;
  if (Q[2] > 1) return false;
  if (Q[3] > 1) return false;
  if (Q[4] > 2) return false;
  if (Q[5] > 1) return false;
  if (Q[6] > 1) return false;
  if (Q[0] == 1 and Q[1] == 2) return false;
  if (Q[3] == 1 and Q[4] == 2) return false;
  return true;
}


int pos(int x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  if (x == 5) return 2;
  if (x == 10) return 3;
  if (x == 20) return 4;
  if (x == 50) return 5;
  if (x == 100) return 6;
  return 7; // 200
}


int main() {
  int n;
  while (cin >> n) {
    Q = VE(8, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++Q[pos(x)];
    }
    cout << (ok() ? "si" : "no") << endl;
  }
}

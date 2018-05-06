#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n;
  while (cin >> n) {
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      V[i] = x - 1;
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
      if (V[i] != -1) {
        int q = 0;
        int j = i;
        while (V[j] != -1) {
          int k = V[j];
          V[j] = -1;
          j = k;
          ++q;
        }
        res += q - 1;
      }
    cout << res << endl;
  }
}

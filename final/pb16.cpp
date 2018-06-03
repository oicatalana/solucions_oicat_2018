#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VVE = vector<VE>;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVE Q(n, VE(27, 0)); // una de mes
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (char c : s) ++Q[i][c-'a'];
    }

    int res = 0;
    for (int i = 1; i < n; ++i) {
      bool ok = true;
      for (int k = 0; ok and k < 26; ++k) {
        int dif = Q[i][k] - Q[0][k];
        if (dif >= 0) Q[i][k+1] += dif;
        else ok = false;
      }
      if (ok) ++res;
    }
    cout << res << endl;
  }
}

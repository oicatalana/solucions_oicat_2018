#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVC M(n, VC(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cin >> M[i][j];
      sort(M[i].begin(), M[i].end());
    }

    int res = 0;
    for (int i = 1; i < n; ++i)
      if (M[i] == M[0]) ++res;
    cout << res << endl;
  }
}

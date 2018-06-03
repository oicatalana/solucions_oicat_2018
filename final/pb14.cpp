#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<string> V(n);
  for (string& s : V) cin >> s;

  int m;
  cin >> m;
  while (m--) { // m vegades
    int p;
    char y;
    cin >> p >> y;
    --p;
    char x = V[0][p];
    int nx = 0;
    int ny = 0;
    for (const string& s : V)
      if (s[p] == x) ++nx;
      else if (s[p] == y) ++ny;
    cout << (2*ny <  nx ? "patologica" : "neutral") << endl;
  }
}

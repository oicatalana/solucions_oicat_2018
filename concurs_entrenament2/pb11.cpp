#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;


int n, m;
VVC mapa;
VVB vist;


bool busca(int f, int c) {
  if (f < 0 or f >= n or c < 0 or c >= m or vist[f][c]) return false;
  vist[f][c] = true;
  if (mapa[f][c] == 't') return true;
  if (mapa[f][c] == 'X') return false;
  return busca(f + 1, c) or busca(f - 1, c) or busca(f, c + 1) or busca(f, c - 1);
}


int main() {
  cin >> n >> m;
  mapa = VVC(n, VC(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> mapa[i][j];
  int f, c;
  cin >> f >> c;
  vist = VVB(n, VB(m, false));
  cout << (busca(f - 1, c - 1) ? "yes" : "no") << endl;
}

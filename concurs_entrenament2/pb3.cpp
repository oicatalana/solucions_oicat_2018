#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;

VE V(10);

bool ok() {
  VE Q(10, 0);
  for (int i = 0; i < 10; ++i) ++Q[V[i]];
  return Q == V;
}

void busca(int i, int falta) {
  if (i == 10) {
    if (ok()) {
      for (int j = 0; j < 10; ++j) cout << V[j];
      cout << endl;
    }
    return;
  }

  for (int j = 0; j <= falta; ++j) {
    V[i] = j;
    busca(i + 1, falta - j);
  }
}

int main() {
  busca(0, 10);
}

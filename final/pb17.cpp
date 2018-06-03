#include <iostream>
#include <vector>
using namespace std;


int q(int x) {
  return x*x;
}


int main() {
  int n;
  cin >> n;
  vector<int> X(n), Y(n), R(n);
  // escollim com a candidat el (un) cercle amb radi minim
  int j = 0;
  for (int i = 0; i < n; ++i) {
    cin >> X[i] >> Y[i] >> R[i];
    if (R[i] < R[j]) j = i;
  }

  bool dins = true;
  for (int i = 0; dins and i < n; ++i)
    if (q(X[i] - X[j]) + q(Y[i] - Y[j]) > q(R[i] - R[j])) dins = false;
  cout << (dins ? "si" : "no") << endl;
}

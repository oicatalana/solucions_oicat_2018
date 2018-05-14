#include <iostream>
#include <vector>
using namespace std;


const int N = 1e5 + 1;
const int MOD = 1e8 + 7;

using VE = vector<int>;

int main() {
  VE F(N);
  F[0] = F[1] = F[2] = 1;
  for (int n = 3; n <= 100000; ++n) F[n] = (F[n-1] + F[n-3])%MOD;

  int n;
  while (cin >> n) cout << F[n] << endl;
}

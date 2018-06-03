#include <iostream>
#include <vector>
using namespace std;


const int N = 1e5 + 1;
const int MOD = 1e8 + 7;


using VE = vector<int>;


VE T(N, -1);


int f(int n) {
  int& res = T[n];
  if (res != -1) return res;
  if (n <= 1) return res = 1;
  if (n == 2) return res = 2;
  return res = (f(n - 1) + f(n - 2) + 3*f(n - 3))%MOD;
}


int main() {
  int n;
  while (cin >> n) cout << f(n) << endl;
}

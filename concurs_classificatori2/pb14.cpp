#include <iostream>
#include <vector>
using namespace std;


const int N = 1e5 + 1;
const int MOD = 1e8 + 7;


using VE = vector<int>;


VE T(N, -1); // -1 vol dir encara no calculat


int f(int n) {
  if (T[n] != -1) return T[n]; // si ja ho hem calculat, ho retornem i prou
  // si encara no està calculat, ho calculem però ho guardem abans de retornar-ho,
  // per no calcular-lo mai més per a aquesta n
  if (n <= 2) return T[n] = 1; // cas base
  return T[n] = (f(n - 1) + f(n - 3))%MOD; // cas general
}


int main() {
  int n;
  while (cin >> n) cout << f(n) << endl;
}

#include <iostream>
using namespace std;


int n;
string s;


void f(int i) {
  // si hem omplert s, l'escrivim i tornem enrera
  if (i == n) {
    cout << s << endl;
    return;
  }

  // posem una A nomes si podem (no crea cap substring prohibit)
  if ((i < 1 or s[i-1] != 'A') and (i < 3 or s.substr(i - 3, 3) != "ABB")) {
    s[i] = 'A';
    f(i + 1);
  }
  // sempre posem una B
  s[i] = 'B';
  f(i + 1);
}


int main() {
  cin >> n;
  s = string(n, '?');
  f(0);
}

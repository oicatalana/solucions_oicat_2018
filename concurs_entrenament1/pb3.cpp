#include <iostream>
#include <cmath>
using namespace std;


bool quad(int n) {
  int x = sqrt(n); //Al ficar el double a un int es trunca (perd els decimals)
  return x*x == n;
}


int main() {
  int n = 9999;
  while (not quad(n) or not quad(n/10)) --n;
  cout << n << endl;
}

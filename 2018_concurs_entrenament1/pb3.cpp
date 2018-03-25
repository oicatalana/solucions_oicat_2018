#include <iostream>
#include <cmath>
using namespace std;


bool quad(int n) {
  int x = sqrt(n);
  return x*x == n;
}


int main() {
  int n = 9999;
  while (not quad(n) or not quad(n/10)) --n;
  cout << n << endl;
}

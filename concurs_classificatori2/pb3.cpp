#include <iostream>
using namespace std;

int primer_digit(int n) {
  if (n < 10) return n;
  return primer_digit(n/10);
}


int nombre_digits(int n) {
  if (n < 10) return 1;
  return 1 + nombre_digits(n/10);
}


int eleva10(int n) {
  if (n == 0) return 1;
  return 10*eleva10(n - 1);
}


int main() {
  for (int n = 60; n < 1000000; ++n)
     if (primer_digit(n) == 6) {
       int pw = eleva10(nombre_digits(n) - 1);
       if (25*(n - 6*pw) == n) cout << n << endl;
     }
}

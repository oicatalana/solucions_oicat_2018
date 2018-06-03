#include <iostream>
using namespace std;


const string taula = "TRWAGMYFPDXBNJZSQVHLCKE";


int main() {
  int n;
  cin >> n;
  cout << n << taula[n%23] << endl;
}

#include <iostream>
using namespace std;


int main() {
  int m;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    cout << (n < 3 ? n : 2*n - 4) << endl;
  }
}

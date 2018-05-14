#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int sum = 0;
  for (int i = 0; i < 9999; ++i) sum += (i%2 ? y : -x);
  cout << sum << endl;
}

#include <iostream>
using namespace std;

bool ok(int a, int b, int c) {
  return a + b*c == 2;
}


int main() {
  for (int x = -100; x <= 100; ++x)
    for (int y = -100; y <= 100; ++y)
      for (int z = -100; z <= 100; ++z)
        if (ok(x, y, z) and ok(y, z, x) and ok(z, x, y))
          cout << x << ' ' << y << ' ' << z << endl;
}


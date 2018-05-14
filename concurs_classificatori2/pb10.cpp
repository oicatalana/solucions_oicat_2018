#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  vector<int> V(5);
  while (cin >> V[0] >> V[1] >> V[2] >> V[3] >> V[4]) {
    sort(V.begin(), V.end());
    cout << V[2] << endl;
  }
}

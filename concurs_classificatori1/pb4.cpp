#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  int x, y, n;
  cin >> x >> y >> n;
  vector<int> a(n + 1);
  a[1] = x;
  for (int i = 2; i <= n; ++i) a[i] = a[i-1] + y*(i - 1);
  cout << a[n] << endl;
}

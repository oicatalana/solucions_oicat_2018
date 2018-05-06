#include <iostream>
using namespace std;

using ll = long long;

bool iguals(ll n) 
{
  int d = n%10;
  n /= 10;
  while (n) {
    if (n%10 != d) return false;
    n /= 10;
  }
  return true;
}


int main() 
{
  for (ll x = 4; x < 1000000; ++x) {
    ll n = x*x;
    if (iguals(n)) cout << n << endl;
  }
}

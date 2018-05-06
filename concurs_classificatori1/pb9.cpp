#include <iostream>
using namespace std;


int main() 
{
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < 4; ++i) 
  {
    sum += n%10;
    n /= 10;
  }
  cout << sum << endl;
}

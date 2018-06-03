#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  do {
    if (s[0] != '0') break;
  } while (next_permutation(s.begin(), s.end()));
  cout << s << endl;
}

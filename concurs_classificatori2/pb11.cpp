#include <iostream>
#include <string>
using namespace std;


bool vocal(char c) {
  if (c == 'a') return true;
  if (c == 'e') return true;
  if (c == 'i') return true;
  if (c == 'o') return true;
  if (c == 'u') return true;
  return false;
}


int main() {
  string s;
  while (cin >> s) {
    if (vocal(s[0])) cout << s;
    else {
      int j = 0;
      while (not vocal(s[++j])) ;
      cout << s.substr(j) << s.substr(0, j);
    }
    cout << "ay" << endl;
  }
}

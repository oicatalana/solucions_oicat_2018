#include <iostream>
#include <map>
using namespace std;


map<string, int> M = {
  {"dilluns",   0},
  {"dimarts",   1},
  {"dimecres",  2},
  {"dijous",    3},
  {"divendres", 4},
  {"dissabte",  5},
  {"diumenge",  6}
};


int main() {
  string a, b;
  cin >> a >> b;
  int x = M[a];
  int y = M[b];
  if (x < y - 3) x += 7;
  else if (y < x - 3) y += 7;
  cout << (x < y ? 'A' : 'B') << endl;
}


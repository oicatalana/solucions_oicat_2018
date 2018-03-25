#include <iostream>
#include <string>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<VVE> VVVE;


VVE mat, fila, colu;
VVVE quad;


bool sudoku(int i, int j) {
  if (i > 8) {
    for (int k = 0; k < 9; ++k) {
      if (k == 3 or k == 6) cout << "------+-------+------" << endl;
      for (int z = 0; z < 9; ++z) {
        if (z == 3 or z == 6) cout << " |";
        cout << (z ? " " : "") << mat[k][z];
      }
      cout << endl;
    }
    cout << endl;
    return true;
  }

  if (j > 8) return sudoku(i + 1, 0);

  if (mat[i][j] > 0) return sudoku(i, j + 1);

  bool res = false;
  for (int a = 1; a <= 9; ++a)
    if (not fila[i][a] and not colu[j][a] and not quad[i/3][j/3][a]) {
      mat[i][j] = a;
      fila[i][a] = colu[j][a] = quad[i/3][j/3][a] = true;
      res = sudoku(i, j + 1) or res;
      fila[i][a] = colu[j][a] = quad[i/3][j/3][a] = false;
      mat[i][j] = 0;
    }
  return res;
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    fila = colu = VVE(9, VE(10, false));
    quad = VVVE(3, VVE(3, VE(10, false)));
    mat = VVE(9, VE(9, 0));

    for (int i = 0; i < 9; ++i) {
      if (i == 3 or i == 6) {
        string s;
        cin >> s;
      }

      for (int j = 0; j < 9; ++j) {
        if (j == 3 or j == 6) {
          char c;
          cin >> c;
        }

        int a;
        cin >> a;
        mat[i][j] = a;
        if (a > 0) fila[i][a] = colu[j][a] = quad[i/3][j/3][a] = true;
      }
    }

    if (not sudoku(0, 0)) cout << "no solution" << endl;
    cout << "******************************" << endl;
  }
}

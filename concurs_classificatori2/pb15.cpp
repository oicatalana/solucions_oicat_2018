#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;   // graf
VE solu; // per guardar la solucio de cada vèrtex


// retorna el nombre de vèrtexs de la component actual
int prof(int x) {
  // si ja hem passat per aqui, sortim i no afegim res al resultat
  if (solu[x] == 0) return 0;
  // marquem x per no tornar a passar per aquí
  solu[x] = 0;
  // de moment hem vist un nou vèrtex (x)
  int res = 1;
  // sumem els nous vèrtexs que podem trobar seguint cada veí
  for (int y : G[x]) res += prof(y);
  // res té la suma acumulada dels vèrtexs nous que hem trobat a partir de x
  return res;
}


// usem el matexi vector solu per guardar el resultat,
// així evitem recàlculs
void marca(int x, int q) {
  // si ja hem passat per aquí, tirem enrera
  if (solu[x] == q) return;
  // guardem el resultat
  solu[x] = q;
  // ho fem per a tots els veïns
  for (int y : G[x]) marca(y, q);
}


// per recordar sumar 1, i no espifiar-la amb el format
void escriu(int x, int q) {
  cout << x + 1 << ": " << q << endl;
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVE(n);
    while (m--) {
      int x, y;
      cin >> x >> y; --x; --y; // restem 1 per començar a partir de 0
      G[x].push_back(y); // y és un veí de x
      G[y].push_back(x); // x és un veí de y
    }

    solu = VE(n, -1); // -1 vol dir no calculat
    int t;
    cin >> t;
    while (t--) { // t vegades
      int x;
      cin >> x; --x;
      if (solu[x] != -1) escriu(x, solu[x]); // si ja estava calculat, l'escrivim i prou
      else {
        int q = prof(x); // calculem el nombre d'element del component
        marca(x, q); // guardem el nombre a tots els vèrtexs del component
        escriu(x, q); // l'escrivim
      }
    }
    cout << string(10, '-') << endl; // 10 guions
  }
}

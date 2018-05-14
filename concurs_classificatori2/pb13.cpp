#include <iostream>
using namespace std;


int n;
string s;


// els boolea ens diu si ja ha sortit abba
void f(int i, bool abba) {
  // si ja hem omplert la paraula, comprovem si compleix la condicio
  // per escriure-la, i en qualsevol cas tirem enrera
  if (i == n) {
    if (abba) cout << s << endl;
    return;
  }

  // primer provem amb A, i actualitzem el boolea si cal
  s[i] = 'A';
  f(i + 1, abba or (i >= 3 and s.substr(i - 3, 3) == "ABB"));
  // despres provem amb B, el qual no pot fer apareixer un nou ABBA
  s[i] = 'B';
  f(i + 1, abba);
}


int main() {
  cin >> n;
  // creem un string de la mida que toca (el contingut inicial
  // no es important pero s'ha de donar)
  s = string(n, '?');
  f(0, false);
}


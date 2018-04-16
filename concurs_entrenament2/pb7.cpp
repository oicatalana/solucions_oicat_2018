#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int resultat = 0;
    for (int i = 1; i <= n; ++i) resultat += i*i;
    cout << resultat << endl;
}

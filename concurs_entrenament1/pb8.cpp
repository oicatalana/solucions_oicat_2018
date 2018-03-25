#include <iostream>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        int copia = n;
        int suma = 0;
        while (n != 0) {
            suma += n%10;
            n /= 10;
        }
        cout << "La suma dels digits de " << copia << " es " << suma << "." << endl;
    }
}

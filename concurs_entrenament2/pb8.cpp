#include <iostream>
using namespace std;


int main() {
    int x;
    cin >> x;
    cout << "El nombre de digits de " << x << " es ";
    int dig = 1;
    while (x > 9) {
        x /= 10;
        ++dig;
    }
    cout << dig << "." << endl;
}

#include <iostream>
using namespace std;


int main() {
    int cas = 1;
    int a, b;
    while (cin >> a >> b) {
        cout << "#" << cas << " : ";
        ++cas;
        if (a%b == 0) cout << a << endl;
        else cout << (a/b + 1)*b << endl;
    }
}

#include <iostream>
using namespace std;


int max(int a, int b) {
    if (a > b) return a;
    else return b;
}


int main() {
    int n;
    while (cin >> n) {
        int m;
        cin >> m;
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            m = max(m, x);
        }
        cout << m << endl;
    }
}

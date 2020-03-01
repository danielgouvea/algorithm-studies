#include <iostream>

using std::cout;
using std::endl;

int gcd(int a, int b) {
    if (b == 0) {
        cout << a << endl;
        return a;
    }

    int remainder = a % b;
    cout << a << " % " << b << " = " << remainder << endl;
    return gcd(b, remainder);
}

int main() {
    gcd(123, 68);
    gcd(68, 123);

    return 0;
}

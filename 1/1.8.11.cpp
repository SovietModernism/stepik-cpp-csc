#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double x1, x2, d;
    d = (b * b) - (4 * a * c);
    if (d >= 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
    cout << x1 << " " << x2;
    } else {
        cout << "No real roots";
    }
    return 0;
}
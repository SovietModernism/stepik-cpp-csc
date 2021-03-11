#include <iostream>
using namespace std;

int main() {
    int a, p;    
    for (cin >> a; cin >> a; p = 0) {
        while (a >> ++p);
        cout << p-1 << endl;
    }
    return 0;
}
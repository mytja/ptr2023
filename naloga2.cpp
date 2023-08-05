#include <iostream>

#define ll long long int

using namespace std;

int main() {
    ll cevapov;
    cin >> cevapov;
    int k = 0;
    for (ll i = 0; i <= cevapov / 9; i++) {
        ll kuhar2 = i * 9;
        ll kuhar1 = cevapov - kuhar2;
        if (kuhar1 % 5 == 0) {
            k++;
            // cout << kuhar1 / 5 << " * 5 + " << i << " * 9" << endl;
        }
    }
    cout << k << endl;
    return 0;
}

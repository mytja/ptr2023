#include <iostream>

using namespace std;

int main() {
    long long int max;
    cin >> max;

    long long int n1 = 1;
    long long int n2 = 1;

    cout << " 0 | " << n1 << endl;

    long long int i = 2;
    while (i < max) {
        long long int s = n2;
        n2 += n1;
        n1 = s;
        if (i < 11) cout << " ";
        cout << i - 1 << " | " << n1 << endl;
        i++;
    }

    cout << max - 1 << " | " << n2 << endl;

    return 0;
}

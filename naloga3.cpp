#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float dolzina, zacOmejitev;
    int n;
    cin >> dolzina >> zacOmejitev >> n;

    cout << fixed;
    cout << setprecision(2);

    n++;

    if (n == 1) {
        cout << floor((dolzina / zacOmejitev) * 100.0) / 100.0 << endl;
        return 0;
    }

    vector<pair<float, float>> znaki(n);

    znaki[0] = {0, zacOmejitev};

    for (int i = 1; i < n; i++) {
        float zacetek, hitrost;
        cin >> zacetek >> hitrost;
        znaki[i] = {zacetek, hitrost};
    }

    float total = 0;

    for (int i = 0; i < n; i++) {
        pair<float, float> znak = znaki[i];
        if (znak.first >= dolzina) break;

        pair<float, float> znak2 = {dolzina, 0};
        if (i + 1 < n) {
            znak2 = znaki[i + 1];
        }
        if (znak2.first > dolzina) {
            znak2 = {dolzina, 0};
        }

        float s = znak2.first - znak.first;
        float v = znak.second;

        if (v == 0) {
            // bizgec ne moreš delit z 0
            continue;
        }

        float t = s/v;
        total += t;
        //cout << t << " " << s << " " << v << endl;
    }

    cout << floor(total * 100.0) / 100.0 << endl;
    return 0;
}

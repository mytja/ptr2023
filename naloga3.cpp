#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int dolzina, zacOmejitev, n;
    cin >> dolzina >> zacOmejitev >> n;

    vector<pair<int, int>> znaki(n);

    for (int i = 0; i < n; i++) {
        int zacetek, hitrost;
        cin >> zacetek >> hitrost;
        znaki[i] = {zacetek, hitrost};
    }

    float total = 0;

    for (int i = 0; i < n; i++) {
        pair<int, int> znak = znaki[i];
        if (znak.first >= dolzina) break;

        pair<int, int> znak2 = {dolzina, 0};
        if (i + 1 < n) {
            znak2 = znaki[i + 1];
        }
        if (znak2.first > dolzina) {
            znak2 = {dolzina, 0};
        }

        float s = znak2.first - znak.first;
        float v = znak.second;

        float t = s/v;
        total += t;
        //cout << t << " " << s << " " << v << endl;
    }

    cout << floor(total * 100) / 100 << endl;
}

#include <iostream>

using namespace std;

int main() {
    int n, dolzina;
    string s;
    cin >> n >> dolzina >> s;
    int zapBilk = 0;
    bool regrat = false;
    for (int i = 0; i < dolzina; i++) {
        if (n <= 0) {
            cout << i << endl;
            return 0;
        }

        char t = s[i];

        // travna bilka
        if (t == '|') {
            // bilka prekine prepoved prehranjevanja z marjeticami
            regrat = false;

            if (zapBilk < 3) {
                n--;
                zapBilk++;
                continue;
            }

            // to izpustimo in resetiramo števec
            zapBilk = 0;
            continue;
        }

        // če ta zadeva ni bilka, resetiramo števec bilk
        zapBilk = 0;

        // marjetice ne smemo jesti po bilkah
        if (t == 'M' && !regrat) {
            n--;
            continue;
        }

        if (t == 'R') {
            n--;
            regrat = true;
            continue;
        }

        // za zemljo že imamo definirano zgoraj zapBilk = 0;
        // posledično nam zdaj ni treba definirati tudi t == '/'
    }

    if (n <= 0) {
        cout << dolzina << endl;
        return 0;
    }

    cout << "DNF" << endl;
    return 0;
}

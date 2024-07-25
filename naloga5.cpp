#include <iostream>

using namespace std;

int vrstic, stolpcev;
int blahajX, blahajY;
int polje[5000*5000];
int h = 0;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vrstic >> stolpcev;
    //polje.resize(vrstic * stolpcev);
    for (int y = 0; y < vrstic; y++) {
        for (int x = 0; x < stolpcev; x++) {
            char c;
            cin >> c;
            polje[y * stolpcev + x] = c == 'H' ? 1 : 0;
            if (c == 'B') {
                blahajX = x;
                blahajY = y;
            }
        }
    }

    for (int x = stolpcev - 2; x > blahajX; x--) {
        for (int y = 0; y < vrstic; y++) {
            int gorDesno = (y == 0) ? 0 : polje[(y - 1) * stolpcev + (x + 1)];
            int desno = polje[y * stolpcev + (x + 1)];
            int dolDesno = (y + 1 == vrstic) ? 0 : polje[(y + 1) * stolpcev + (x + 1)];
            polje[y * stolpcev + x] += max(gorDesno, max(desno, dolDesno));
        }
    }

    int gorDesno = (blahajY == 0) ? 0 : polje[(blahajY - 1) * stolpcev + (blahajX + 1)];
    int desno = polje[blahajY * stolpcev + (blahajX + 1)];
    int dolDesno = (blahajY + 1 == vrstic) ? 0 : polje[(blahajY + 1) * stolpcev + (blahajX + 1)];
    cout << max(gorDesno, max(desno, dolDesno)) << "\n";
    return 0;
}

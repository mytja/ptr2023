#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Sidrisce {
    int x;
    int y;
    int tocke;
    bool raziskano;
};

int stolpcev, vrstic;
int umagX, umagY, resevalnaX, resevalnaY;
vector<Sidrisce> sidrisca;

void printSidrisca() {
    for (int i = 0; i < stolpcev * vrstic; i++) {
        if (i % stolpcev == 0) cout << endl;
        cout << sidrisca[i].tocke << " ";
    }
    cout << endl << "------------------" << endl;
}

queue<Sidrisce> sosednjaSidrisca(int x, int y) {
    queue<Sidrisce> q;
    if (x + 1 < stolpcev && !sidrisca[y * stolpcev + x + 1].raziskano) {
        // desno sidrišče
        q.push(sidrisca[y * stolpcev + x + 1]);
    }
    if (x > 0 && !sidrisca[y * stolpcev + x - 1].raziskano) {
        // levo sidrišče
        q.push(sidrisca[y * stolpcev + x - 1]);
    }
    if (y > 0 && !sidrisca[(y - 1) * stolpcev + x].raziskano) {
        // zgornje sidrišče
        q.push(sidrisca[(y - 1) * stolpcev + x]);
    }
    if (y + 1 < vrstic && !sidrisca[(y + 1) * stolpcev + x].raziskano) {
        // spodnje sidrišče
        q.push(sidrisca[(y + 1) * stolpcev + x]);
    }
    return q;
}

Sidrisce najmanjseNeraziskano() {
    Sidrisce najmanjse;
    najmanjse.tocke = INT_MAX;
    for (int i = 0; i < stolpcev * vrstic; i++) {
        if (sidrisca[i].tocke < najmanjse.tocke && !sidrisca[i].raziskano) {
            najmanjse = sidrisca[i];
        }
    }
    return najmanjse;
}

void dijkstra() {
    queue<Sidrisce> q = sosednjaSidrisca(resevalnaX, resevalnaY);
    Sidrisce trenutnoSidrisce = sidrisca[resevalnaY * stolpcev + resevalnaX];

    while (true) {
        //cout << umagX << " " << umagY << " / " << trenutnoSidrisce.x << " " << trenutnoSidrisce.y << endl;
        if (umagX == trenutnoSidrisce.x && umagY == trenutnoSidrisce.y) return;

        while (q.size() != 0) {
            Sidrisce s = q.front();
            q.pop();
            if (trenutnoSidrisce.tocke + 1 < sidrisca[s.y * stolpcev + s.x].tocke) {
                // če je nov rezultat manjši, posodobimo trenutni rezultat
                sidrisca[s.y * stolpcev + s.x].tocke = trenutnoSidrisce.tocke + 1;
            }
        }

        sidrisca[trenutnoSidrisce.y * stolpcev + trenutnoSidrisce.x].raziskano = true;

        //printSidrisca();

        trenutnoSidrisce = najmanjseNeraziskano();
        //cout << trenutnoSidrisce.x << " " << trenutnoSidrisce.y << endl;
        q = sosednjaSidrisca(trenutnoSidrisce.x, trenutnoSidrisce.y);
    }
}

int main() {
    cin >> stolpcev >> vrstic;
    sidrisca.resize(stolpcev * vrstic);
    for (int i = 0; i < stolpcev * vrstic; i++) {
        sidrisca[i].raziskano = false;
        sidrisca[i].tocke = INT_MAX;
        sidrisca[i].x = i % stolpcev;
        sidrisca[i].y = i / stolpcev;
    }

    cin >> umagX >> umagY >> resevalnaX >> resevalnaY;
    umagX--;
    umagY--;
    resevalnaX--;
    resevalnaY--;

    sidrisca[umagY * stolpcev + umagX].raziskano = false;
    sidrisca[resevalnaY * stolpcev + resevalnaX].tocke = 0;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        if (y1 == y2) {
            // ladja je sidrana vodoravno
            for (int n = min(x1, x2); n <= max(x1, x2); n++) {
                sidrisca[stolpcev * y1 + n].raziskano = true;
            }
        } else {
            // ladja je sidrana navpično
            for (int n = min(y1, y2); n <= max(y1, y2); n++) {
                sidrisca[stolpcev * n + x1].raziskano = true;
            }
        }
    }

    dijkstra();

    // predvidevam da ni potrebno pristati na ladjo, temveč samo ob njo
    cout << sidrisca[umagY * stolpcev + umagX].tocke - 1 << endl;

    return 0;
}

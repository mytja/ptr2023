#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tocka {
    int x;
    int y;
    int k;
    int tocke;
};

struct Pot {
    Tocka hranaOd;
    Tocka hranaDo;
};

vector<Tocka> hrana;

bool blahajLahkoDoseze(const Tocka& hranaOd, const Tocka& hranaDo) {
    //cout << "hranaOd: " << hranaOd.x << "/" << hranaOd.y << " " << hranaDo.x << "/" << hranaDo.y << endl;
    if (hranaOd.x >= hranaDo.x) return false;
    int deltaX = abs(hranaOd.x - hranaDo.x);
    int deltaY = abs(hranaOd.y - hranaDo.y);
    // blahaj se vedno premakne desno. Torej, če je deltaY striktno večji od deltaX, blahaj ne more
    // doseči hrane.
    return deltaY <= deltaX;
}

vector<Pot> sosedi(Tocka h1) {
    vector<Pot> poti;
    for (int i = 0; i < hrana.size(); i++) {
        Tocka h2 = hrana[i];
        if (h2.k == h1.k) continue;
        if (blahajLahkoDoseze(h1, h2)) {
            Pot pot;
            pot.hranaOd = h1;
            pot.hranaDo = h2;
            poti.push_back(pot);
        }
    }
    return poti;
}

int main() {
    int h, w;
    cin >> h >> w;
    Tocka blahaj;
    int k = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int n = 0; n < w; n++) {
            char t = s[n];
            if (t == 'H') {
                Tocka h;
                h.x = n;
                h.y = i;
                h.k = k;
                h.tocke = 0;
                hrana.push_back(h);

                k++;
            } else if (t == 'B') {
                blahaj.x = n;
                blahaj.y = i;
                blahaj.k = -1;
                blahaj.tocke = 0;
            }
        }
    }

    queue<Pot> poti;
    vector<Pot> zacetneTocke = sosedi(blahaj);
    for (int i = 0; i < zacetneTocke.size(); i++) {
        poti.push(zacetneTocke[i]);
    }

    // gremo čez vso hrano, pogledamo katero hrano lahko blahaj doseže
    // bfs algoritem (?)
    // počutil sem se fancy in sem dejansko uporabil queue
    while (poti.size() != 0) {
        Pot pot = poti.front();
        poti.pop();

        //cout << "pot " << pot.hranaOd.x << "/" << pot.hranaOd.y << endl;

        Tocka hranaOd = hrana[pot.hranaOd.k];
        Tocka hranaDo = hrana[pot.hranaDo.k];

        int novo = hranaOd.tocke + 1;
        if (hranaDo.tocke >= novo) {
            continue;
        }

        //cout << "nova točka" << endl;
        hrana[pot.hranaDo.k].tocke = novo;

        vector<Pot> zacetneTocke = sosedi(hranaDo);
        for (int i = 0; i < zacetneTocke.size(); i++) {
            poti.push(zacetneTocke[i]);
        }
    }

    int m = 0;
    for (int i = 0; i < k + 1; i++) {
        m = max(hrana[i].tocke, m);
    }

    cout << m << endl;
}

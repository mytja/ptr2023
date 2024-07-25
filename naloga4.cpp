#include <iostream>
#include <queue>

using namespace std;

int stolpcev, vrstic;
int umagX, umagY, resevalnaX, resevalnaY;
int k;

int mesta[2005*2005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> stolpcev >> vrstic;
    cin >> umagX >> umagY >> resevalnaX >> resevalnaY;
    cin >> k;
    for (int i = 0; i < stolpcev * vrstic; i++) {
        mesta[i] = -1;
    }
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            // ladja je zasidrana po vrsticah
            for (int y = y1; y <= y2; y++) {
                mesta[y * stolpcev + x1] = -2;
            }
        } else {
            // ladja je zasidrana po stolpcih
            for (int x = x1; x <= x2; x++) {
                mesta[y1 * stolpcev + x] = -2;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({resevalnaX, resevalnaY});
    mesta[resevalnaY * stolpcev + resevalnaX] = 0;
    while (q.size() != 0) {
        auto s = q.front();
        q.pop();
        int oddaljenost = mesta[s.second * stolpcev + s.first] + 1;
        // sosedi
        int x[4] = {s.first, s.first + 1, s.first, s.first - 1};
        int y[4] = {s.second - 1, s.second, s.second + 1, s.second};
        for (int i = 0; i < 4; i++) {
            if (x[i] >= stolpcev || x[i] < 0) continue;
            if (y[i] >= vrstic || y[i] < 0) continue;
            if (mesta[y[i] * stolpcev + x[i]] != -1) continue;
            mesta[y[i] * stolpcev + x[i]] = oddaljenost;
            if (x[i] == umagX && y[i] == umagY) {
                cout << oddaljenost << "\n";
                return 0;
            }
            q.push({x[i], y[i]});
        }
    }

    cout << "neveljevni input podatki!\n";
    return 0;
}

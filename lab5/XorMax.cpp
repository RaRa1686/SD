#include <iostream>
#include <vector>
using namespace std;

const int BITI = 30;

struct Nod {
    Nod* copii[2];
    int index;
};
Nod* nodNou() {
    Nod* nod = new Nod;
    nod->copii[0] = NULL;
    nod->copii[1] = NULL;
    nod->index = -1;
    return nod;
}
Nod* radacina;

void insereaza(int valoare, int idx) {
    Nod* nod = radacina;
    for (int b = BITI; b >= 0; b--) {
        int bit = (valoare >> b) & 1;
        if (nod->copii[bit] == NULL) nod->copii[bit] = nodNou();
        nod = nod->copii[bit];
    }
    nod->index = idx;
}
int interogheaza(int valoare) {
    Nod* nod = radacina;
    for (int b = BITI; b >= 0; b--) {
        int bit = (valoare >> b) & 1;
        int opus = 1 - bit;
        if (nod->copii[opus] != NULL) nod = nod->copii[opus];
        else nod = nod->copii[bit];
    }
    return nod->index;
}
int main() {
    vector<int> a = {3, 8, 2, 6, 4};
    int n = a.size();

    vector<int> pref(n + 1, 0);
    for (int r = 1; r <= n; r++) pref[r] = pref[r - 1] ^ a[r - 1];

    radacina = nodNou();

    int maxim = -1, bi = -1, bj = -1;
    for (int r = 2; r <= n; r++) {
        insereaza(pref[r - 2], r - 2);
        int l = interogheaza(pref[r]);
        int val = pref[r] ^ pref[l];
        if (val > maxim) { maxim = val; bi = l; bj = r - 1; }
    }

    cout << "xor maxim = " << maxim << "\n";
    cout << "indici i = " << bi << ", j = " << bj << "\n";

    return 0;
}

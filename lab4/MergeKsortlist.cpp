#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Nod {
    int val;
    Nod* urm;
};
Nod* nodNou(int x) {
    Nod* nod = new Nod;
    nod->val = x;
    nod->urm = NULL;
    return nod;
}
Nod* construieste(vector<int> valori) {
    Nod* cap = NULL;
    Nod* coada = NULL;
    for (int x : valori) {
        Nod* nod = nodNou(x);
        if (cap == NULL) { cap = nod; coada = nod; }
        else { coada->urm = nod; coada = nod; }
    }
    return cap;
}
Nod* uneste(vector<Nod*> liste) {
    priority_queue<pair<int, Nod*>, vector<pair<int, Nod*>>, greater<pair<int, Nod*>>> minHeap;
    for (Nod* lista : liste)
        if (lista != NULL) minHeap.push({lista->val, lista});
    Nod* cap = NULL;
    Nod* coada = NULL;
    while (!minHeap.empty()) {
        Nod* minim = minHeap.top().second;
        minHeap.pop();
        if (minim->urm != NULL) minHeap.push({minim->urm->val, minim->urm});
        if (cap == NULL) { cap = minim; coada = minim; }
        else { coada->urm = minim; coada = minim; }
    }
    if (coada != NULL) coada->urm = NULL;
    return cap;
}
void afiseaza(Nod* t) {
    while (t != NULL) {
        cout << t->val << " ";
        t = t->urm;
    }
    cout << "\n";
}
int main() {
    vector<Nod*> liste;
    liste.push_back(construieste({1, 4, 7}));
    liste.push_back(construieste({2, 5, 8}));
    liste.push_back(construieste({3, 6, 9}));

    Nod* rezultat = uneste(liste);
    afiseaza(rezultat);

    return 0;
}

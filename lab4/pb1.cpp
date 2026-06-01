#include <iostream>
#include <vector>
using namespace std;

struct Nod {
    int cheie;
    Nod* stanga;
    Nod* dreapta;
};
Nod* nodNou(int x) {
    Nod* nod = new Nod;
    nod->cheie = x;
    nod->stanga = NULL;
    nod->dreapta = NULL;
    return nod;
}
bool exista(Nod* t, int x) {
    while (t != NULL) {
        if (x == t->cheie) return true;
        if (x < t->cheie) t = t->stanga;
        else t = t->dreapta;
    }
    return false;
}
void insereaza(Nod*& t, int x) {
    if (t == NULL) { t = nodNou(x); return; }
    if (x < t->cheie)      insereaza(t->stanga, x);
    else if (x > t->cheie) insereaza(t->dreapta, x);
}
void sterge(Nod*& t, int x) {
    if (t == NULL) return;
    if (x < t->cheie)      sterge(t->stanga, x);
    else if (x > t->cheie) sterge(t->dreapta, x);
    else {
        if (t->stanga == NULL) {
            Nod* deSters = t;
            t = t->dreapta;
            delete deSters;
        } else if (t->dreapta == NULL) {
            Nod* deSters = t;
            t = t->stanga;
            delete deSters;
        } else {
            Nod* minim = t->dreapta;
            while (minim->stanga != NULL) minim = minim->stanga;
            t->cheie = minim->cheie;
            sterge(t->dreapta, minim->cheie);
        }
    }
}
int predecesor(Nod* t, int x) {
    int rezultat = -1;
    while (t != NULL) {
        if (t->cheie < x) { rezultat = t->cheie; t = t->dreapta; }
        else t = t->stanga;
    }
    return rezultat;
}
int succesor(Nod* t, int x) {
    int rezultat = -1;
    while (t != NULL) {
        if (t->cheie > x) { rezultat = t->cheie; t = t->stanga; }
        else t = t->dreapta;
    }
    return rezultat;
}
int main() {
    Nod* radacina = NULL;
    int v[] = {5, 2, 8, 1, 9, 3, 7};
    for (int x : v) insereaza(radacina, x);

    cout << "exista(8) = " << exista(radacina, 8) << "\n";
    cout << "exista(4) = " << exista(radacina, 4) << "\n";

    insereaza(radacina, 4);
    cout << "dupa insert(4): exista(4) = " << exista(radacina, 4) << "\n";

    sterge(radacina, 8);
    cout << "dupa erase(8): exista(8) = " << exista(radacina, 8) << "\n";

    cout << "predecesor(7) = " << predecesor(radacina, 7) << "\n";
    cout << "succesor(7) = "   << succesor(radacina, 7)   << "\n";

    return 0;
}

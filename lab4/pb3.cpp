#include <iostream>
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

Nod* primul;
Nod* alDoilea;
Nod* anterior;

void cautaGreseli(Nod* t) {
    if (t == NULL) return;
    cautaGreseli(t->stanga);
    if (anterior != NULL && anterior->cheie > t->cheie) {
        if (primul == NULL) primul = anterior;
        alDoilea = t;
    }
    anterior = t;
    cautaGreseli(t->dreapta);
}
void repara(Nod* radacina) {
    primul = NULL;
    alDoilea = NULL;
    anterior = NULL;
    cautaGreseli(radacina);
    if (primul != NULL && alDoilea != NULL) {
        int aux = primul->cheie;
        primul->cheie = alDoilea->cheie;
        alDoilea->cheie = aux;
    }
}
void inordine(Nod* t) {
    if (t == NULL) return;
    inordine(t->stanga);
    cout << t->cheie << " ";
    inordine(t->dreapta);
}
int main() {
    Nod* r = nodNou(5);
    r->stanga = nodNou(8);
    r->dreapta = nodNou(3);
    r->stanga->stanga = nodNou(1);
    r->stanga->dreapta = nodNou(4);
    r->dreapta->dreapta = nodNou(9);

    cout << "inainte: ";
    inordine(r);
    cout << "\n";

    repara(r);

    cout << "dupa:    ";
    inordine(r);
    cout << "\n";

    return 0;
}

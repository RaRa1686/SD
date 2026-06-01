#include <iostream>
#include <climits>
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
bool verifica(Nod* t, long long minim, long long maxim) {
    if (t == NULL) return true;
    if (t->cheie <= minim || t->cheie >= maxim) return false;
    return verifica(t->stanga, minim, t->cheie) &&
           verifica(t->dreapta, t->cheie, maxim);
}
bool esteBST(Nod* t) {
    return verifica(t, LLONG_MIN, LLONG_MAX);
}
int main() {
    Nod* r1 = nodNou(5);
    r1->stanga = nodNou(3);
    r1->dreapta = nodNou(8);
    r1->stanga->stanga = nodNou(1);
    r1->stanga->dreapta = nodNou(4);
    r1->dreapta->dreapta = nodNou(9);
    cout << "arbore 1 este BST = " << esteBST(r1) << "\n";

    Nod* r2 = nodNou(5);
    r2->stanga = nodNou(3);
    r2->dreapta = nodNou(8);
    r2->dreapta->stanga = nodNou(4);
    cout << "arbore 2 este BST = " << esteBST(r2) << "\n";

    return 0;
}

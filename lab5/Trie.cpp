#include <iostream>
#include <string>
using namespace std;

struct Nod {
    Nod* copii[26];
    int cuvinte;
    int treceri;
};
Nod* nodNou() {
    Nod* nod = new Nod;
    for (int i = 0; i < 26; i++) nod->copii[i] = NULL;
    nod->cuvinte = 0;
    nod->treceri = 0;
    return nod;
}

Nod* radacina = nodNou();

void insereaza(string s) {
    Nod* nod = radacina;
    for (char c : s) {
        int i = c - 'a';
        if (nod->copii[i] == NULL) nod->copii[i] = nodNou();
        nod = nod->copii[i];
        nod->treceri++;
    }
    nod->cuvinte++;
}
int numara(string s) {
    Nod* nod = radacina;
    for (char c : s) {
        int i = c - 'a';
        if (nod->copii[i] == NULL) return 0;
        nod = nod->copii[i];
    }
    return nod->cuvinte;
}
int prefixMaxim(string s) {
    Nod* nod = radacina;
    int lungime = 0;
    for (char c : s) {
        int i = c - 'a';
        if (nod->copii[i] == NULL) break;
        nod = nod->copii[i];
        lungime++;
    }
    return lungime;
}

Nod* stergeNod(Nod* nod, string& s, int poz) {
    if (poz == (int)s.size()) {
        nod->cuvinte--;
    } else {
        int i = s[poz] - 'a';
        nod->copii[i] = stergeNod(nod->copii[i], s, poz + 1);
    }
    if (poz > 0) {
        nod->treceri--;
        if (nod->treceri == 0) {
            delete nod;
            return NULL;
        }
    }
    return nod;
}
void sterge(string s) {
    if (numara(s) == 0) return;
    radacina = stergeNod(radacina, s, 0);
}
int main() {
    insereaza("cat");
    insereaza("car");
    insereaza("card");
    insereaza("car");

    cout << "count(car) = "  << numara("car")  << "\n";
    cout << "count(card) = " << numara("card") << "\n";
    cout << "count(ca) = "   << numara("ca")   << "\n";

    cout << "prefixMaxim(care) = " << prefixMaxim("care") << "\n";
    cout << "prefixMaxim(dog) = "  << prefixMaxim("dog")  << "\n";

    sterge("card");
    cout << "dupa erase(card): count(card) = " << numara("card") << "\n";
    cout << "count(car) = " << numara("car") << "\n";
    cout << "prefixMaxim(card) = " << prefixMaxim("card") << "\n";

    return 0;
}

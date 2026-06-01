#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

struct Nod
{
    int cheie;
    Nod *stanga;
    Nod *dreapta;
};
Nod *nodNou(int x)
{
    Nod *nod = new Nod;
    nod->cheie = x;
    nod->stanga = NULL;
    nod->dreapta = NULL;
    return nod;
}
void serializeazaRec(Nod *t, string &rezultat)
{
    if (t == NULL)
        return;
    rezultat += to_string(t->cheie) + " ";
    serializeazaRec(t->stanga, rezultat);
    serializeazaRec(t->dreapta, rezultat);
}
string serializeaza(Nod *t)
{
    string rezultat = "";
    serializeazaRec(t, rezultat);
    return rezultat;
}
Nod *construieste(vector<int> &valori, int &pozitie, long long minim, long long maxim)
{
    if (pozitie >= (int)valori.size())
        return NULL;
    int val = valori[pozitie];
    if (val <= minim || val >= maxim)
        return NULL;
    pozitie++;
    Nod *nod = nodNou(val);
    nod->stanga = construieste(valori, pozitie, minim, val);
    nod->dreapta = construieste(valori, pozitie, val, maxim);
    return nod;
}
Nod *deserializeaza(string text)
{
    vector<int> valori;
    stringstream ss(text);
    int x;
    while (ss >> x)
        valori.push_back(x);
    int pozitie = 0;
    return construieste(valori, pozitie, LLONG_MIN, LLONG_MAX);
}
void inordine(Nod *t)
{
    if (t == NULL)
        return;
    inordine(t->stanga);
    cout << t->cheie << " ";
    inordine(t->dreapta);
}
int main()
{
    Nod *r = nodNou(5);
    r->stanga = nodNou(3);
    r->dreapta = nodNou(8);
    r->stanga->stanga = nodNou(1);
    r->stanga->dreapta = nodNou(4);
    r->dreapta->dreapta = nodNou(9);

    string text = serializeaza(r);
    cout << "serializat: " << text << "\n";

    Nod *refacut = deserializeaza(text);
    cout << "inordine arbore refacut: ";
    inordine(refacut);
    cout << "\n";

    return 0;
}

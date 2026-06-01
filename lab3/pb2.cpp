#include <iostream>
#include <vector>
using namespace std;

vector<int> chei;
vector<int> stare;         
int n = 0, folosite = 0, m = 8;

int poz(int x) { return ((x % m) + m) % m; }
void resize();
bool exists(int x) {
    for (int p = poz(x), i = 0; i < m; i++, p = (p + 1) % m) {
        if (stare[p] == 0) return false;
        if (stare[p] == 1 && chei[p] == x) return true;
    }
    return false;
}
void insert(int x) {
    if (exists(x)) return;
    if (folosite + 1 > m * 0.7) resize();
    int p = poz(x);
    while (stare[p] == 1) p = (p + 1) % m;
    if (stare[p] == 0) folosite++;
    stare[p] = 1; chei[p] = x; n++;
}
void erase(int x) {
    for (int p = poz(x), i = 0; i < m; i++, p = (p + 1) % m) {
        if (stare[p] == 0) return;
        if (stare[p] == 1 && chei[p] == x) { stare[p] = 2; n--; return; }
    }
}
void resize() {
    vector<int> ck = chei, st = stare;
    m *= 2; chei.assign(m, 0); stare.assign(m, 0); n = 0; folosite = 0;
    for (int i = 0; i < (int)ck.size(); i++)
        if (st[i] == 1) insert(ck[i]);
}
int main() {
    chei.assign(m, 0); stare.assign(m, 0);
    for (int x = 0; x < 10; x++) insert(x);
    insert(5);  
    cout << "exists(5)  = " << exists(5)  << "\n";  
    cout << "exists(42) = " << exists(42) << "\n";  
    erase(5);
    cout << "dupa erase(5): exists(5) = " << exists(5) << "\n";  
    cout << "exists(6) = " << exists(6) << "\n";                 
    return 0;
}

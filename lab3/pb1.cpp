#include <iostream>
#include <vector>
#include <list>

std::vector<std::list<int>> table;  
int n = 0;                         
int m = 8;                         
int hash_index(int x) {
    int h = x % m;
    if (h < 0) h += m;   // ca sa nu iasa index negativ
    return h;
}

// exists x : cautam x in lista lui
bool exists(int x) {
    for (int val : table[hash_index(x)])
        if (val == x) return true;
    return false;
}

// resize: dublam tabelul si reinseram tot
void resize() {
    std::vector<std::list<int>> vechi = table;  // copie a datelor vechi
    m = m * 2;
    table.assign(m, std::list<int>());           // tabel nou, gol
    for (auto& bucket : vechi)
        for (int x : bucket)
            table[hash_index(x)].push_back(x);
}
void insert(int x) {
    if (exists(x)) return;          // fara duplicate

    if (n + 1 > m * 3 / 4)          // daca trecem de 75% plin -> marim
        resize();

    table[hash_index(x)].push_back(x);
    n++;
}
void erase(int x) {
    if (exists(x)) {
        table[hash_index(x)].remove(x);
        n--;
    }
}
int main() {
    table.assign(m, std::list<int>());   // initializam tabelul gol

    for (int x = 0; x < 12; x++) insert(x);
    insert(3);  

    std::cout << "exists(3)  = " << exists(3)  << "\n";  
    std::cout << "exists(50) = " << exists(50) << "\n";  

    erase(3);
    std::cout << "dupa erase(3): exists(3) = " << exists(3) << "\n";  

    return 0;
}

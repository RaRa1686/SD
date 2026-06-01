#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long u64;

const u64 BAZA = 131;   
u64 hashSir(const string& s) {
    u64 h = 0;
    for (char c : s)
        h = h * BAZA + (u64)(c - 'a' + 1);  
    return h;
}
int main() {
    vector<string> siruri = {"abc", "abd", "abc", "xyz"};
    int m = 16;   
    for (auto& s : siruri) {
        u64 h = hashSir(s);
        cout << s << " -> hash = " << h
             << ", slot = " << (h % m) << "\n";
    }
    return 0;
}

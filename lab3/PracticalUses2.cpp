#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long atMost(vector<int>& a, int k) {
    if (k < 0) return 0;
    map<int, int> freq;
    int stanga = 0;
    long long rezultat = 0;
    for (int dreapta = 0; dreapta < a.size(); dreapta++) {
        freq[a[dreapta]]++;
        while (freq.size() > k) {
            freq[a[stanga]]--;
            if (freq[a[stanga]] == 0)
                freq.erase(a[stanga]);
            stanga++;
        }
        rezultat += dreapta - stanga + 1;
    }
    return rezultat;
}
int main() {
    int n, l, u;
    cin >> n >> l >> u;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << atMost(a, u) - atMost(a, l - 1) << endl;

    return 0;
}

#include <iostream>
using namespace std;

int rel[1001][1001];  

bool knows(int i, int j) {
    return rel[i][j] == 1; // daca i il cunaoste pe j ;)
}

int GasimCelebritate(int n) {
    int candidat = 0;
    for (int i = 1; i < n; i++)
        if (knows(candidat, i))
            candidat = i;
    for (int i = 0; i < n; i++) {
        if (i == candidat) continue;
        if (knows(candidat, i) || !knows(i, candidat))
            return -1;
    }
    return candidat;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> rel[i][j];
    int rez = GasimCelebritate(n);
    if (rez == -1)
        cout << endl;
    else
        cout << rez << endl;

    return 0;
}

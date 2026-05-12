#include <iostream>
using namespace std;
int main(){
    int n, a[1000][1000], linie, coloana, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    linie = 0;
    coloana = n - 1;
    cin >> x;
    while (linie < n && coloana >= 0){
        if (a[linie][coloana] == x){
            cout << linie << " " << coloana;
            break;
        }
        else if (a[linie][coloana] < x)
            linie ++;
            else
            coloana --;
    }
    if (linie >= n || coloana < 0)
        cout << "nu exista";
    return 0;
}

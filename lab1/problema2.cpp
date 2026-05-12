#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n , s, stanga, dreapta, v[10000], i, j, suma;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    cin >> v[i];
    stanga = 0;
    dreapta = n-1;
    int best_diff = INT_MAX;
    while (stanga < dreapta){
        suma = v[stanga] + v[dreapta];
        int diff = abs(suma - s);
        if (diff < best_diff){
            best_diff = diff;
            i = stanga;
            j = dreapta;
        }
        if (suma < s)
        stanga ++;
        else if (suma > s)
        dreapta --; 
        else break;
    }
    cout << i << endl << j;
    cout  << v[i] + v[j];
}

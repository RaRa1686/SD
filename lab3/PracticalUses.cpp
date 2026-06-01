#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n , s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 2; i++){
    int stanga = i + 1;
    int dreapta = n - 1;
    while (stanga < dreapta){
        int suma = a[i] + a[stanga] + a[dreapta];
        if (suma == s){
            cout << a[i] << "+ " << a[stanga] << "+" << a[dreapta] << "=" << suma << endl;
            return 0;
        }
        else
            if (suma < s)
                stanga++;
            else
                dreapta--;
    }
    }
    cout << "nu exista" << endl;
    return 0;
}

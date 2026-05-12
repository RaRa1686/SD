#include <iostream>
using namespace std;
int main(){
    int n , q , v[1000], prefix[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    prefix[0] = v[0];
    for (int i = 1 ; i < n; i++)
    prefix[i] = prefix[i-1] + v[i];
    cin >> q;
    for (int i = 0; i < n;i++){
        int l , r;
        if (l == 0)
            cout << prefix[r] << endl;
            else
            cout << prefix[r] - prefix[l-1] << endl;
    }
return 0;
}

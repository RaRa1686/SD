#include <iostream>
using namespace std;

void QuickSort(int v[], int st, int dr){
    if (st < dr){
        int m = (st + dr) / 2;
        swap(v[st], v[m]);
        int i = st, j = dr, d = 0;
        while (i < j){
            if (v[i] > v[j]){
                swap(v[i], v[j]);
                d = 1 - d;
            }
            i = i + d;
            j -= 1 - d;
        }
        QuickSort(v, st, i-1);
        QuickSort(v, i+1, dr);
    }
}

int main(){
    int n , k;
    cin >> n >> k;
    int v[200001];
    for(int i = 0; i < n; i++)
    cin >> v[i];
    QuickSort(v, 0 , n - 1);
    cout << v[k - 1];
    return 0;

}

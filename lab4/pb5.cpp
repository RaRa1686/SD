#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void urca(int i) {
    while (i > 0) {
        int parinte = (i - 1) / 2;
        if (heap[i] > heap[parinte]) {
            swap(heap[i], heap[parinte]);
            i = parinte;
        } else {
            break;
        }
    }
}
void coboara(int i) {
    int n = heap.size();
    while (true) {
        int stanga = 2 * i + 1;
        int dreapta = 2 * i + 2;
        int maxim = i;
        if (stanga < n && heap[stanga] > heap[maxim]) maxim = stanga;
        if (dreapta < n && heap[dreapta] > heap[maxim]) maxim = dreapta;
        if (maxim == i) break;
        swap(heap[i], heap[maxim]);
        i = maxim;
    }
}
void insereaza(int x) {
    heap.push_back(x);
    urca(heap.size() - 1);
}
int top() {
    return heap[0];
}
void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) coboara(0);
}
int main() {
    int v[] = {5, 2, 8, 1, 9, 3};
    for (int x : v) insereaza(x);

    cout << "top = " << top() << "\n";
    pop();
    cout << "top dupa pop = " << top() << "\n";

    insereaza(10);
    cout << "top dupa insert(10) = " << top() << "\n";

    cout << "scoatem tot: ";
    while (!heap.empty()) {
        cout << top() << " ";
        pop();
    }
    cout << "\n";

    return 0;
}

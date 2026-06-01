#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long costMinim(vector<int> lungimi) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int x : lungimi) minHeap.push(x);
    long long cost = 0;
    while (minHeap.size() > 1) {
        long long a = minHeap.top(); minHeap.pop();
        long long b = minHeap.top(); minHeap.pop();
        cost += a + b;
        minHeap.push(a + b);
    }
    return cost;
}
int main() {
    vector<int> lungimi = {4, 3, 2, 6};
    cout << "cost minim = " << costMinim(lungimi) << "\n";
    return 0;
}

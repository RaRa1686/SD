#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> josMax;
priority_queue<int, vector<int>, greater<int>> susMin;

void insereaza(int x) {
    if (josMax.empty() || x <= josMax.top()) josMax.push(x);
    else susMin.push(x);

    if (josMax.size() > susMin.size() + 1) {
        susMin.push(josMax.top());
        josMax.pop();
    } else if (susMin.size() > josMax.size()) {
        josMax.push(susMin.top());
        susMin.pop();
    }
}
double median() {
    if (josMax.size() > susMin.size()) return josMax.top();
    return (josMax.top() + susMin.top()) / 2.0;
}
int main() {
    int v[] = {5, 2, 8, 1, 9};
    for (int x : v) {
        insereaza(x);
        cout << "dupa " << x << " -> median = " << median() << "\n";
    }
    return 0;
}

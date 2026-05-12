#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("strabunica.in");
ofstream fout("strabunica.out");

int main() {
    int n;
    fin >> n;
    int v[200001];
    for (int i = 0; i < n; i++)
        fin >> v[i];
    stack<int> st;
    long long maxArie = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] >= v[i]) {
            int h = v[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArie = max(maxArie, (long long)h * w);
        }
        st.push(i);
    }
    while (!st.empty()) {
        int h = v[st.top()];
        st.pop();
        int w = st.empty() ? n : n - st.top() - 1;
        maxArie = max(maxArie, (long long)h * w);
    }
    fout << maxArie;
    return 0;
}

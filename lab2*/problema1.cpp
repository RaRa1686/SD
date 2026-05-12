#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    int v[20001];
    for(int i = 0; i < n; i++)
    cin >> v[i];
    stack <int> st;
    for (int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i])
        st.pop();

        if (st.empty())
        cout << -1 << " ";
        else
        cout << st.top() << " ";
        st.push(i);
    }
    return 0;

}

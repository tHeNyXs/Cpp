#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for(int &x:h) cin >> x;

    vector<int> L(n,1), R(n,1);

    stack<int> st;

    // left -> right
    for(int i=0;i<n;i++){

        while(!st.empty() && h[st.top()] < h[i]){
            L[i] = max(L[i], L[st.top()] + 1);
            st.pop();
        }

        if(!st.empty())
            L[i] = max(L[i], L[st.top()] + 1);

        st.push(i);
    }

    while(!st.empty()) st.pop();

    // right -> left
    for(int i=n-1;i>=0;i--){

        while(!st.empty() && h[st.top()] < h[i]){
            R[i] = max(R[i], R[st.top()] + 1);
            st.pop();
        }

        if(!st.empty())
            R[i] = max(R[i], R[st.top()] + 1);

        st.push(i);
    }

    int ans = 0;

    for(int i=0;i<n;i++)
        ans = max(ans, L[i] + R[i] - 1);

    cout << ans << "\n";
}
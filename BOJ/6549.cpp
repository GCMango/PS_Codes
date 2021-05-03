#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int N;
        ll mx = 0;
        cin >> N;
        if (N == 0) break;
        vector<ll> arr(N);
        stack<int> st;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ll cur = st.top();
                st.pop();
                int width = i;
                if (!st.empty())
                    width -= st.top() + 1;
                mx = max(mx, arr[cur] * width);
            }
            st.push(i);
        }
    
        while (!st.empty()) {
            ll cur = st.top();
            st.pop();
            int width = N;
            if (!st.empty())
                width -= st.top() + 1;
            mx = max(mx, arr[cur] * width);
        }
    
        cout << mx << "\n";
    }

    return 0;
}


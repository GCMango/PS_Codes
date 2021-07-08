#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt = 0, r = 0; cin >> N;
    stack<int> st;
    for (int i = 0; i < N; ++i) {
        int n, mx = 0, scnt = 0; cin >> n;
        while (!st.empty()) {
            r++;
            if (st.top() > n) { cnt++; break; }
            if (st.top() >= mx) cnt++;
            mx = max(mx, st.top());
            if (st.top() == n) scnt++;
            st.pop();
        }
        for (int j = 0; j < scnt; ++j) { r++; st.push(n); }
        st.push(n);
    }
    cout << cnt << '\n';
    cout << r << '\n';

    return 0;
}

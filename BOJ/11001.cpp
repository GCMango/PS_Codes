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

const int MXN = 100000;
int N, D;
ll T[MXN + 1], V[MXN + 1], opt[MXN + 1], ans;

void dfs(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) >> 1;
    ll res = 0;
    for (int i = max(l, m - D); i <= min(m, r); ++i) {
        if (res < (m - i) * T[m] + V[i]) {
            res = (m - i) * T[m] + V[i];
            opt[m] = i;
        }
    }
    ans = max(ans, res);
    dfs(s, m - 1, l, opt[m]);
    dfs(m + 1, e, opt[m], r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> D;
    for (int i = 1; i <= N; ++i) cin >> T[i];
    for (int i = 1; i <= N; ++i) cin >> V[i];
    dfs(1, N, 1, N);
    cout << ans << '\n';

    return 0;
}

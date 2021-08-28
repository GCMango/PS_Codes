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

const int MXN = 100001;
int N, sz = 0, stk[MXN];
ll dist[MXN], dp[MXN];
pll arr[MXN];
vector<pll> g[MXN];

double cross(int x, int y) { return 1.0 * (dp[y] - dp[x]) / (dist[y] - dist[x]); }

void dfs(int x, int p, ll d) {
    int idx, ostk, osz;
    dist[x] = d;

    if (p) {
        int s = 0, e = sz - 1;
        while (s < e) {
            int m = (s + e + 1) / 2;
            if (cross(stk[m - 1], stk[m]) <= arr[x].y) s = m;
            else e = m - 1;
        }
        int y = stk[s];
        dp[x] = arr[x].y * (dist[x] - dist[y]) + dp[y] + arr[x].x;
    
        s = 1, e = sz;
        while (s < e) {
            int m = (s + e) / 2;
            if (cross(stk[m - 1], stk[m]) > cross(stk[m], x)) e = m;
            else s = m + 1;
        }
        idx = s, ostk = stk[idx], osz = sz;
        stk[idx] = x, sz = idx + 1;
    }

    // dp[x] = min(dp[x], dp[cur] + (dist[x] - dist[cur]) * arr[x].y + arr[x].x);
    // dp[x] = min(dp[x], - dist[cur] * arr[x].y + dp[cur] + dist[x] * arr[x].y + arr[x].x);

    for (auto &[n, m] : g[x])
        if (n != p) dfs(n, x, d + m);

    if (p) stk[idx] = ostk, sz = osz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    for (int i = 2; i <= N; ++i) cin >> arr[i].x >> arr[i].y;

    dfs(1, 0, 0);

    for (int i = 2; i <= N; ++i) cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}

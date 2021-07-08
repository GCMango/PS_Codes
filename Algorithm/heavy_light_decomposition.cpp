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

struct Seg {
    int tree[1 << 18];
    int sz = 1 << 17;
    void update(int x, int v) {
        x |= sz; tree[x] += v;
        while (x >>= 1) tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
    int query(int l, int r) {
        l |= sz, r |= sz;
        int res = 0;
        while (l <= r) {
            if (l & 1) res += tree[l++];
            if (~r & 1) res += tree[r--];
            l >>= 1, r >>= 1;
        }
        return res;
    }
} seg;

int sz[MXN + 1], dep[MXN + 1], par[MXN + 1], top[MXN + 1], in[MXN + 1], out[MXN + 1];
vector<int> g[MXN + 1], inp[MXN + 1];

bool chk[MXN + 1];
void dfs(int x = 1) {
    chk[x] = 1;
    for (auto i : inp[x]) {
        if (chk[i]) continue;
        chk[i] = 1;
        g[x].push_back(i);
        dfs(i);
    }
}

void dfs1(int x = 1) {
    sz[x] = 1;
    for (auto &i : g[x]) {
        dep[i] = dep[x] + 1; par[i] = x;
        dfs1(i); sz[x] += sz[i];
        if (sz[i] > sz[g[x][0]]) swap(i, g[x][0]);
    }
}

int cnt = 0;
void dfs2(int x = 1) {
    in[x] = ++cnt;
    for (auto i : g[x]) {
        top[i] = i == g[x][0] ? top[x] : i;
        dfs2(i);
    }
    out[x] = cnt;
}

void update(int x, int v) {
    seg.update(in[x], v);
}

int query(int s, int e) {
    int res = 0;
    while (top[s] ^ top[e]) {
        if (dep[top[s]] < dep[top[e]]) swap(s, e);
        int st = top[s];
        res += seg.query(in[st], in[s]);
        s = par[st];
    }
    if (dep[s] > dep[e]) swap(s, e);
    res += seg.query(in[s], in[e]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i < N; ++i) {
        int s, e; cin >> s >> e;
        inp[s].push_back(e);
        inp[e].push_back(s);
    }
    dfs(); dfs1(); dfs2();
    while (M--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) update(a, b);
        else cout << query(a, b) << '\n';
    }

    return 0;
}


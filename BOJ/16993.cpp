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

struct Val { int m, l, r, s; };

const int MXN = 100001;
int arr[MXN];
Val tree[MXN * 4];

Val init(int x, int s, int e) {
    if (s == e) return tree[x] = {arr[s], arr[s], arr[s], arr[s]};
    int m = (s + e) / 2;
    Val a = init(x * 2, s, m), b = init(x * 2 + 1, m + 1, e);
    Val res = {a.r + b.l, max(a.l, a.s + b.l), max(b.r, b.s + a.r), a.s + b.s};
    res.m = max({res.m, res.l, res.r, res.s, a.m, b.m});
    return tree[x] = res;
}

Val query(int x, int s, int e, int l, int r) {
    if (s > r || e < l) return {0, 0, 0, -(int)2e9};
    if (l <= s && e <= r) return tree[x];
    int m = (s + e) / 2;
    Val a = query(x * 2, s, m, l, r), b = query(x * 2 + 1, m + 1, e, l, r), res;
    if (a.s == -(int)2e9) res = {b.m, b.l, b.r, b.s};
    else if (b.s == -(int)2e9) res = {a.m, a.l, a.r, a.s};
    else {
        res = {a.r + b.l, max(a.l, a.s + b.l), max(b.r, b.s + a.r), a.s + b.s};
        res.m = max({res.m, res.l, res.r, res.s, a.m, b.m});
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    init(1, 1, N);

    int M; cin >> M;
    while (M--) {
        int l, r; cin >> l >> r;
        Val res = query(1, 1, N, l, r);
        cout << res.m << '\n';
    }

    return 0;
}

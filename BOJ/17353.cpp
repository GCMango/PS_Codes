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
ll arr[MXN], tree[MXN * 4], lazy[MXN * 4];

void propagate(int x, int s, int e) {
    if (lazy[x]) {
        tree[x] += (e - s + 1) * lazy[x];
        if (s != e)
            lazy[x * 2] += lazy[x], lazy[x * 2 + 1] += lazy[x];
        lazy[x] = 0;
    }
}

void update(int x, int s, int e, int l, int r, ll v) {
    propagate(x, s, e);
    if (s > r || e < l) return;
    if (l <= s && e <= r) {
        lazy[x] += v;
        propagate(x, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(x * 2, s, m, l, r, v), update(x * 2 + 1, m + 1, e, l, r, v);
    tree[x] = tree[x * 2] + tree[x * 2 + 1];
}

ll query(int x, int s, int e, int l, int r) {
    propagate(x, s, e);
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return tree[x];
    int m = (s + e) / 2;
    return query(x * 2, s, m, l, r) + query(x * 2 + 1, m + 1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        update(1, 1, N, i, i, arr[i] - arr[i - 1]);
    }

    int Q; cin >> Q;
    while (Q--) {
        int n; cin >> n;
        if (n == 1) {
            int l, r; cin >> l >> r;
            update(1, 1, N, l, r, 1);
            update(1, 1, N, r + 1, r + 1, -(r - l + 1));
        }
        else {
            int x; cin >> x;
            cout << query(1, 1, N, 1, x) << '\n';
        }
    }

    return 0;
}

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

const int MXN = (int)1e5;
vector<int> tree[MXN * 4];

void update(int s, int e, int cur, int idx, int val) {
    if (idx < s || idx > e) return;
    tree[cur].push_back(val);
    if (s == e) return;
    int m = (s + e) / 2;
    update(s, m, cur * 2, idx, val);
    update(m + 1, e, cur * 2 + 1, idx, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        update(1, N, 1, i, n);
    }
    for (int i = 0; i < MXN * 4; ++i) sort(all(tree[i]));
    while (M--) {
        int i, j, k; cin >> i >> j >> k;

    }

    return 0;
}

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MOD = 1e9 + 7;

int N, M, K;
vector<ll> input;
vector<ll> tree;

ll init_tree(ll start, ll fin, ll cur) {
    if (start == fin) return tree[cur] = input[start];
    ll mid = (start + fin) / 2;
    return tree[cur] = (init_tree(start, mid, cur * 2) * init_tree(mid + 1, fin, cur * 2 + 1)) % MOD;
}

ll get_mul(ll start, ll fin, ll cur, ll left, ll right) {
    if (left > fin || right < start) return 1;
    if (left <= start && fin <= right) return tree[cur];
    ll mid = (start + fin) / 2;
    return (get_mul(start, mid, cur * 2, left, right) * get_mul(mid + 1, fin, cur * 2 + 1, left, right)) % MOD;
}

ll update_tree(ll start, ll fin, ll cur, ll idx, ll ch) {
    if (idx < start || idx > fin) return tree[cur];
    if (start == fin) return tree[cur] = ch;
    ll mid = (start + fin) / 2;
    return tree[cur] = (update_tree(start, mid, cur * 2, idx, ch) * update_tree(mid + 1, fin, cur * 2 + 1, idx, ch)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    M += K;
    input.resize(N + 1);
    tree.resize(N * 4);
    for (int i = 1; i <= N; ++i) cin >> input[i];

    init_tree(1, N, 1);

    while (M--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n == 1)
            update_tree(1, N, 1, a, b);
        else
            cout << get_mul(1, N, 1, a, b) << "\n";
    }

    return 0;
}


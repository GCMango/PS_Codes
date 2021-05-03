#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll N, M, K;
vector<ll> input;
vector<ll> tree;

ll init_tree(ll start, ll fin, ll cur) {
    if (start == fin) return tree[cur] = input[start];
    ll mid = (start + fin) / 2;
    return tree[cur] = init_tree(start, mid, cur * 2) + init_tree(mid + 1, fin, cur * 2 + 1);
}

ll get_sum(ll start, ll fin, ll cur, ll left, ll right) {
    if (left > fin || right < start) return 0;
    if (left <= start && fin <= right) return tree[cur];
    ll mid = (start + fin) / 2;
    return get_sum(start, mid, cur * 2, left, right) + get_sum(mid + 1, fin, cur * 2 + 1, left, right);
}

void update_tree(ll start, ll fin, ll cur, ll idx, ll ch) {
    if (idx < start || idx > fin) return;
    tree[cur] += (ch - input[idx]);
    if (start == fin) return;
    ll mid = (start + fin) / 2;
    update_tree(start, mid, cur * 2, idx, ch);
    update_tree(mid + 1, fin, cur * 2 + 1, idx, ch);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    M += K;
    input.resize(N + 1);
    tree.resize(N * 4);
    for (ll i = 1; i <= N; ++i)
        cin >> input[i];

    init_tree(1, N, 1);

    while (M--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update_tree(1, N, 1, b, c);
            input[b] = c;
        }
        else
            cout << get_sum(1, N, 1, b, c) << "\n";
    }

    return 0;
}

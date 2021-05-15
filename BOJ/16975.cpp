#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

int N, M;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<ll> input;
vector<pll> tree;

ll init_tree(ll start, ll fin, ll cur) {
    if (start == fin) return tree[cur].x = input[start];
    ll mid = (start + fin) / 2;
    return tree[cur].x = init_tree(start, mid, cur * 2) + init_tree(mid + 1, fin, cur * 2 + 1);
}

ll get_val(ll start, ll fin, ll cur, ll idx) {
    if (tree[cur].y != 0) {
        tree[cur].x += (fin - start + 1) * tree[cur].y;
        if (start != fin) {
            tree[cur * 2].y += tree[cur].y;
            tree[cur * 2 + 1].y += tree[cur].y;
        }
        tree[cur].y = 0;
    }
    if (idx > fin || idx < start) return 0;
    if (start == fin) return tree[cur].x;
    ll mid = (start + fin) / 2;
    return get_val(start, mid, cur * 2, idx) + get_val(mid + 1, fin, cur * 2 + 1, idx);
}

void update_tree(ll start, ll fin, ll cur, ll left, ll right, ll ch) {
    if (tree[cur].y != 0) {
        tree[cur].x += (fin - start + 1) * tree[cur].y;
        if (start != fin) {
            tree[cur * 2].y += tree[cur].y;
            tree[cur * 2 + 1].y += tree[cur].y;
        }
        tree[cur].y = 0;
    }

    if (right < start || left > fin) return;

    if (start >= left && fin <= right) {
        tree[cur].x += (fin - start + 1) * ch;
        if (start != fin) {
            tree[cur * 2].y += ch;
            tree[cur * 2 + 1].y += ch;
        }
        return;
    }

    ll mid = (start + fin) / 2;

    update_tree(start, mid, cur * 2, left, right, ch);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, ch);

    tree[cur].x = tree[cur * 2].x + tree[cur * 2 + 1].x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    input.resize(N + 1);
    tree.resize(N * 4, {0, 0});
    for (int i = 1; i <= N; ++i) cin >> input[i];

    init_tree(1, N, 1);

    cin >> M;
    while (M--) {
        int n, a, b, c;
        cin >> n;
        if (n == 1) {
            cin >> a >> b >> c;
            update_tree(1, N, 1, a, b, c);
        }
        else {
            cin >> a;
            cout << get_val(1, N, 1, a) << "\n";
        }
    }

    return 0;
}


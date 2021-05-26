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

int N, M, cnt = 0;
ll cash[500001], tree[2000002], lazy[2000002];
pii range[500001];
vector<vector<int>> graph;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void propagate(int start, int fin, int cur) {
    if (lazy[cur] != 0) {
        tree[cur] += (fin - start + 1) * lazy[cur];
        if (start != fin) {
            lazy[cur * 2] += lazy[cur];
            lazy[cur * 2 + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void update_seg(int start, int fin, int cur, int left, int right, int val) {
    propagate(start, fin, cur);
    if (right < start || left > fin) return;
    if (left <= start && fin <= right) {
        lazy[cur] += val;
        propagate(start, fin, cur);
        return;
    }
    int mid = (start + fin) / 2;
    update_seg(start, mid, cur * 2, left, right, val);
    update_seg(mid + 1, fin, cur * 2 + 1, left, right, val);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

ll get_cash(int start, int fin, int cur, int idx) {
    propagate(start, fin, cur);
    if (idx < start || idx > fin) return 0;
    if (start == fin) return tree[cur];
    int mid = (start + fin) / 2;
    return get_cash(start, mid, cur * 2, idx) + get_cash(mid + 1, fin, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> cash[i];
        if (i == 1) continue;
        cin >> x;
        graph[x].push_back(i);
    }

    init_tree(1);

    for (int i = 1; i <= N; ++i)
        update_seg(1, N, 1, range[i].x, range[i].x, cash[i]);
    while (M--) {
        char opt;
        int a, b;
        cin >> opt;
        if (opt == 'p') {
            cin >> a >> b;
            if (range[a].x == range[a].y) continue;
            update_seg(1, N, 1, range[a].x + 1, range[a].y, b);
        }
        else {
            cin >> a;
            cout << get_cash(1, N, 1, range[a].x) << '\n';
        }
    }

    return 0;
}

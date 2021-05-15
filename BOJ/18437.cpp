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
vector<vector<int>> graph;
vector<pii> range;
vector<pii> tree;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void init_seg(int start, int fin, int cur) {
    tree[cur].x = fin - start + 1;
    if (start == fin) return;
    int mid = (start + fin) / 2;
    init_seg(start, mid, cur * 2);
    init_seg(mid + 1, fin, cur * 2 + 1);
}

void prop(int start, int fin, int cur) {
    if (tree[cur].y == -1) return;
    tree[cur].x = (fin - start + 1) * tree[cur].y;
    if (start != fin)
        tree[cur * 2].y = tree[cur * 2 + 1].y = tree[cur].y;
    tree[cur].y = -1;
}

void update_tree(int start, int fin, int cur, int left, int right, int val) {
    prop(start, fin, cur);

    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        tree[cur].y = val;
        prop(start, fin, cur);
        return;
    }

    int mid = (start + fin) / 2;

    update_tree(start, mid, cur * 2, left, right, val);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, val);

    tree[cur].x = tree[cur * 2].x + tree[cur * 2 + 1].x;
}

int get_val(int start, int fin, int cur, int left, int right) {
    prop(start, fin, cur);

    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return tree[cur].x;

    int mid = (start + fin) / 2;

    return get_val(start, mid, cur * 2, left, right) + get_val(mid + 1, fin, cur * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    range.resize(N + 1);
    tree.resize(N * 4, {0, -1});

    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        graph[n].push_back(i);
    }

    init_tree(1);
    init_seg(1, N, 1);

    cin >> M;
    while (M--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 || n == 2) {
            update_tree(1, N, 1, range[m].x + 1, range[m].y, (n == 1 ? 1 : 0));
        }
        else
            cout << get_val(1, N, 1, range[m].x + 1, range[m].y) << '\n';
    }

    return 0;
}

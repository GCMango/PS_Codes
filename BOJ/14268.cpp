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

int N, M, cnt;
vector<vector<int>> graph;
vector<pii> range;
vector<pii> tree;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void update_tree(int start, int fin, int cur, int left, int right, int val) {
    if (tree[cur].y != 0) {
        tree[cur].x += (fin - start + 1) * tree[cur].y;
        if (start != fin) {
            tree[cur * 2].y += tree[cur].y;
            tree[cur * 2 + 1].y += tree[cur].y;
        }
        tree[cur].y = 0;
    }

    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        tree[cur].x += (fin - start + 1) * val;
        if (start != fin) {
            tree[cur * 2].y += val;
            tree[cur * 2 + 1].y += val;
        }
        return;
    }

    int mid = (start + fin) / 2;

    update_tree(start, mid, cur * 2, left, right, val);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, val);

    tree[cur].x = tree[cur * 2].x + tree[cur * 2 + 1].x;
}

int get_val(int start, int fin, int cur, int idx) {
    if (tree[cur].y != 0) {
        tree[cur].x += (fin - start + 1) * tree[cur].y;
        if (start != fin) {
            tree[cur * 2].y += tree[cur].y;
            tree[cur * 2 + 1].y += tree[cur].y;
        }
        tree[cur].y = 0;
    }

    if (idx < start || fin < idx) return 0;
    if (start == fin) return tree[cur].x;

    int mid = (start + fin) / 2;

    return get_val(start, mid, cur * 2, idx) + get_val(mid + 1, fin, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    range.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;
        if (n == -1) continue;
        graph[n].push_back(i);
    }

    init_tree(1);

    while (M--) {
        int n, i, w;
        cin >> n;
        if (n == 1) {
            cin >> i >> w;
            update_tree(1, N, 1, range[i].x, range[i].y, w);
        }
        else {
            cin >> i;
            cout << get_val(1, N, 1, range[i].x) << '\n';
        }
    }

    return 0;
}

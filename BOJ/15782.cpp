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

int N, M, cnt = 0, input[100001];
pii range[100001];
pll tree[400004];
vector<vector<int>> graph;

void init_tree(int cur, int pnode) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        if (next != pnode)
            init_tree(next, cur);
    range[cur].y = cnt;
}

void update_tree(int start, int fin, int cur, int left, int right, int val) {
    int k = (fin - start + 1) % 2 == 0 ? 0 : tree[cur].y;
    tree[cur].x ^= k;
    if (start != fin) {
        tree[cur * 2].y ^= tree[cur].y;
        tree[cur * 2 + 1].y ^= tree[cur].y;
    }
    tree[cur].y = 0;

    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        k = (fin - start + 1) % 2 == 0 ? 0 : val;
        tree[cur].x ^= k;
        if (start != fin) {
            tree[cur * 2].y ^= val;
            tree[cur * 2 + 1].y ^= val;
        }
        return;
    }

    int mid = (start + fin) / 2;
    update_tree(start, mid, cur * 2, left, right, val);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, val);

    tree[cur].x = tree[cur * 2].x ^ tree[cur * 2 + 1].x;
}

int get_xor(int start, int fin, int cur, int left, int right) {
    int k = (fin - start + 1) % 2 == 0 ? 0 : tree[cur].y;
    tree[cur].x ^= k;
    if (start != fin) {
        tree[cur * 2].y ^= tree[cur].y;
        tree[cur * 2 + 1].y ^= tree[cur].y;
    }
    tree[cur].y = 0;

    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return tree[cur].x;

    int mid = (start + fin) / 2;
    return get_xor(start, mid, cur * 2, left, right) ^ get_xor(mid + 1, fin, cur * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    init_tree(1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> input[i];
        update_tree(1, N, 1, range[i].x, range[i].x, input[i]);
    }

    while (M--) {
        int n, x, y;
        cin >> n;
        if (n == 1) {
            cin >> x;
            cout << get_xor(1, N, 1, range[x].x, range[x].y) << '\n';
        }
        else {
            cin >> x >> y;
            update_tree(1, N, 1, range[x].x, range[x].y, y);
        }
    }

    return 0;
}

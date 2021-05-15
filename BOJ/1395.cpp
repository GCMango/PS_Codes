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

int N, M;
vector<pii> tree;

void update_tree(int start, int fin, int cur, int left, int right) {
    if (tree[cur].y == 1) {
        tree[cur].x = (fin - start + 1) - tree[cur].x;
        if (start != fin) {
            tree[cur * 2].y = !tree[cur * 2].y;
            tree[cur * 2 + 1].y = !tree[cur * 2 + 1].y;
        }
        tree[cur].y = !tree[cur].y;
    }
    
    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        tree[cur].x = (fin - start + 1) - tree[cur].x;
        if (start != fin) {
            tree[cur * 2].y = !tree[cur * 2].y;
            tree[cur * 2 + 1].y = !tree[cur * 2 + 1].y;
        }
        return;
    }

    int mid = (start + fin) / 2;

    update_tree(start, mid, cur * 2, left, right);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right);

    tree[cur].x = tree[cur * 2].x + tree[cur * 2 + 1].x;
}

int get_num(int start, int fin, int cur, int left, int right) {
    if (tree[cur].y == 1) {
        tree[cur].x = (fin - start + 1) - tree[cur].x;
        if (start != fin) {
            tree[cur * 2].y = !tree[cur * 2].y;
            tree[cur * 2 + 1].y = !tree[cur * 2 + 1].y;
        }
        tree[cur].y = !tree[cur].y;
    }

    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return tree[cur].x;

    int mid = (start + fin) / 2;

    return get_num(start, mid, cur * 2, left, right) + get_num(mid + 1, fin, cur * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    tree.resize(N * 4);

    while (M--) {
        int O, S, T;
        cin >> O >> S >> T;
        if (O == 0)
            update_tree(1, N, 1, S, T);
        else
            cout << get_num(1, N, 1, S, T) << "\n";
    }

    return 0;
}

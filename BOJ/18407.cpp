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

int N;
int tree[800008], lazy[800008];
pii input[100001];
vector<int> v;

void propagate(int start, int fin, int cur) {
    if (lazy[cur] != 0) {
        tree[cur] = max(tree[cur], lazy[cur]);
        if (start != fin) {
            lazy[cur * 2] = max(lazy[cur * 2], lazy[cur]);
            lazy[cur * 2 + 1] = max(lazy[cur * 2 + 1], lazy[cur]);
        }
        lazy[cur] = 0;
    }
}

int get_height(int start, int fin, int cur, int left, int right) {
    propagate(start, fin, cur);
    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return tree[cur];
    int mid = (start + fin) / 2;
    return max(get_height(start, mid, cur * 2, left, right), get_height(mid + 1, fin, cur * 2 + 1, left, right));
}

void update_tree(int start, int fin, int cur, int left, int right, int val) {
    propagate(start, fin, cur);
    if (right < start || left > fin) return;
    if (left <= start && fin <= right) {
        lazy[cur] = max(lazy[cur], val);
        propagate(start, fin, cur);
        return;
    }
    int mid = (start + fin) / 2;
    update_tree(start, mid, cur * 2, left, right, val);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, val);
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        input[i] = {b, b + a - 1};
        v.push_back(b);
        v.push_back(b + a - 1);
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    auto find_idx = [&](int x) { return lower_bound(all(v), x) - v.begin(); };

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int a = find_idx(input[i].x), b = find_idx(input[i].y);
        a++; b++;
        int c = get_height(1, N * 2, 1, a, b);
        update_tree(1, N * 2, 1, a, b, c + 1);
        ans = max(ans, c + 1);
    }

    cout << ans << '\n';

    return 0;
}

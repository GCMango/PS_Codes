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

const int MAX = 100001;

int N, tree[400004], lazy[400004];

void propagate(int s, int e, int cur) {
    if (lazy[cur] != 0) {
        tree[cur] += lazy[cur];
        if (s != e) {
            lazy[cur * 2] += lazy[cur];
            lazy[cur * 2 + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void update(int s, int e, int cur, int l, int r) {
    propagate(s, e, cur);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[cur]++;
        propagate(s, e, cur);
        return;
    }
    int m = (s + e) / 2;
    update(s, m, cur * 2, l, r);
    update(m + 1, e, cur * 2 + 1, l, r);
}

int get_flowers(int s, int e, int cur, int idx) {
    propagate(s, e, cur);
    if (idx < s || e < idx) return 0;
    if (idx <= s && e <= idx) {
        int result = tree[cur];
        tree[cur] = 0;
        return result;
    }
    int m = (s + e) / 2;
    return get_flowers(s, m, cur * 2, idx) + get_flowers(m + 1, e, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        update(1, MAX, 1, l + 1, r - 1);
        cout << get_flowers(1, MAX, 1, l) + get_flowers(1, MAX, 1, r) << '\n';
    }

    return 0;
}

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

int N, M, arr[500005], tree[2000002];

void init(int s, int e, int cur) {
    if (s == e) { tree[cur] = arr[s]; return; }
    int m = (s + e) / 2;
    init(s, m, cur * 2); init(m + 1, e, cur * 2 + 1);
}

void propagate(int s, int e, int cur) {
    if (tree[cur] != 0 && s != e) {
        tree[cur * 2] += tree[cur];
        tree[cur * 2 + 1] += tree[cur];
        tree[cur] = 0;
    }
}

void update(int s, int e, int cur, int l, int r) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[cur]++;
        propagate(s, e, cur);
        return;
    }
    int m = (s + e) / 2;
    update(s, m, cur * 2, l, r); update(m + 1, e, cur * 2 + 1, l, r);
}

void res(int s, int e, int cur, int idx) {
    propagate(s, e, cur);
    if (idx < s || e < idx) return;
    if (s == e) {
        arr[s] = tree[cur];
        return;
    }
    int m = (s + e) / 2;
    res(s, m, cur * 2, idx); res(e, m + 1, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= N; ++i) arr[i] = i - 1;
        while (M--) {
            int n;
            cin >> n;
            res(1, N, 1, n);
            cout << arr[n] << ' ';
            arr[1] = 0;
            update(1, N, 1, 2, n);
        }
        cout << '\n';
    }

    return 0;
}

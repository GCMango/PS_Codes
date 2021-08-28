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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int cnt[200002] = {}, ans = N;
    while (M--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        if (!cnt[u]) ans--;
        cnt[u]++;
    }

    int Q; cin >> Q;
    while (Q--) {
        int n; cin >> n;
        int u, v;
        if (n == 1) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            if (!cnt[u]) ans--;
            cnt[u]++;
        }
        else if (n == 2) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            cnt[u]--;
            if (!cnt[u]) ans++;
        }
        else cout << ans << '\n';
    }

    return 0;
}

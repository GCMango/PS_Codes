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

typedef pair<int, bool> pib;

void solve() {
    int N, M;
    pib point[100001];
    bool alive[100001];
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> point[i].x;
    for (int i = 0; j < N; ++i) { char c; cin >> c; point[i].y = c == 'L' ? 0 : 1; }
    sort(point, point + N, [&](pib &a, pib &b) {
        return a.x < b.x;
    });

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

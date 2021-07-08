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

    int T; cin >> T;
    while (T--) {
        int N, u, v, w, b;
        cin >> N >> u >> v;
        cin >> w >> b;
        if ((u + v) / 2 >= w && N - (u + v + 1) / 2 >= b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

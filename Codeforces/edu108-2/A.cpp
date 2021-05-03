#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    int r, b, d;
    cin >> r >> b >> d;
    int ans = max(r, b) / min(r, b) + (max(r, b) % min(r, b) != 0);
    if (ans - 1 <= d) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

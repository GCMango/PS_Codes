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

void solve() {
    vector<int> a(4), b(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    b = a;
    sort(rall(b));
    int m = max(a[0], a[1]), n = max(a[2], a[3]);
    if ((b[0] == m && b[1] == n) || (b[0] == n && b[1] == m))
        cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

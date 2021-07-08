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
        int a, b, n;
        cin >> n >> a >> b;
        if (n == 1 || b == 1) { cout << "Yes\n"; continue; }
        if (a == 1) {
            if (n % b == 1) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }
        bool ok = 0;
        ll cur = 1;
        while (cur <= n) {
            if ((n - cur) % b == 0) ok = 1;
            cur *= a;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    ll N;
    cin >> N;
    if (N == 0) { cout << 0 << "\n"; return; }
    ll x = N, len = 0;
    bool poss = true;
    if (N < 2050) poss = false;
    while (x != 0) {
        x /= 10;
        len++;
    }
    ll start = 2050 * pow(10, len - 4);
    ll sum = 0;
    for (ll i = start; i >= 2050; i /= 10) {
        sum += N / i;
        N %= i;
        if (N < 2050 && N > 0) poss = false;
    }
    if (poss)
        cout << sum << "\n";
    else
        cout << -1 << "\n";
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

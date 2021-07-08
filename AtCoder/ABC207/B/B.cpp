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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= c * d) { cout << "-1\n"; return 0; }
    a += b; c *= d; d = c;
    int cnt = 1;
    while (a > c) {
        a += b;
        c += d;
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}

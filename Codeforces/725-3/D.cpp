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

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    int ans_a = 0, ans_b = 0, x = gcd(a, b);
    for (int i = 2; i <= a;) {
        if (a % i == 0) { ans_a++; a /= i; }
        else i++;
    }
    for (int i = 2; i <= b;) {
        if (b % i == 0) { ans_b++; b /= i; }
        else i++;
    }
    if (a == b) {
        if (k <= ans_a + ans_b) cout << "YES";
        else cout << "NO";
    }
    else {
        if (k - k / 2 <= cnt) cout << "YES";
        else cout << "NO";
    }
    cout << '\n';
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

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

int dp[55][55][55][55];

int L(int a, int b, int c, int d) {
    if (a < b) { swap(a, b); swap(c, d); }
    if (!c && !d && a % b == 0) return a / b;
    if (dp[a][b][c][d]) return dp[a][b][c][d];
    int ans = 1e9;
    for (int i = 1; i < a; ++i) {
        if (i < c) ans = min(ans, L(i, b - d, 0, 0) + L(a - i, b, c - i, d));
        else if (i == c) ans = min(ans, L(i, b - d, 0, 0) + L(a - i, b, 0, 0));
        else ans = min(ans, L(i, b, c, d) + L(a - i, b, 0, 0));
    }
    for (int i = 1; i < b; ++i) {
        if (i < b - d) ans = min(ans, L(a, i, 0, 0) + L(a, b - i, c, d));
        else if (i == b - d) ans = min(ans, L(a, i, 0, 0) + L(a - c, b - i, 0, 0));
        else ans = min(ans, L(a, i, c, i - (b - d)) + L(a - c, b - i, 0, 0));
    }
    return dp[a][b][c][d] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << L(a, b, c, d) << '\n';

    return 0;
}

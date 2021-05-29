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
    int N, arr[] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    string s = "NO";
    cin >> N;
    for (int i = 0; i < 8; ++i) {
        N %= 11 * arr[i];
        if (i != 7)
            N %= arr[i];
    }
    if (N == 1 || N == 0) s = "YES";
    cout << s << '\n';
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

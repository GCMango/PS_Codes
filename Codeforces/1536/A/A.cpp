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
        int N, mn = 1e9;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int n; cin >> n;
            mn = min(mn, n);
        }
        if (mn < 0) cout << "NO\n";
        else {
            cout << "YES\n300\n";
            for (int i = 0; i < 300; ++i) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}

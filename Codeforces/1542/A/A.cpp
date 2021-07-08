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
        int N, odd = 0, even = 0;
        cin >> N;
        for (int i = 0; i < 2 * N; ++i) {
            int n; cin >> n;
            if (n % 2) odd++;
            else even++;
        }
        if (odd == even) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

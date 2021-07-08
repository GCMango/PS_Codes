#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    double N;
    cin >> N;
    double cnt = 1;
    for (int i = 1; i <= 30; ++i) {
        cnt *= 2;
        double r = sqrt(N / cnt);
        if (floor(r) == r) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << "\n";

    int t = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T') t++;
        else m++;
        if (m > t) {
            cout << "NO";
            return;
        }
    }
    t = 0, m = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'T') t++;
        else m++;
        if (m > t) {
            cout << "NO";
            return;
        }
    }
    if (t != m * 2) {
        cout << "NO";
        return;
    }
    cout << "YES";
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

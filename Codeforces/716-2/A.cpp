#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    int N;
    bool is_true = true;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        bool perfect = false;
        for (int i = 0; i <= num; ++i) {
            if (i * i == num) {
                perfect = true;
                break;
            }
        }
        if (!perfect) is_true = false;
    }
    if (is_true) cout << "NO\n";
    else cout << "YES\n";
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

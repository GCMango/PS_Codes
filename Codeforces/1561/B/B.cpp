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
        int a, b; cin >> a >> b;
        int n = a + b, h1 = n / 2, h2 = (n + 1) / 2;
        if (a < b) swap(a, b);
        vector<bool> chk(n + 1);
        chk[a - h1] = chk[a - h2] = 1;
        for (int i = 1; i <= n - a; ++i)
            chk[a - h1 + 2 * i] = 1;
        for (int i = 1; i <= n - a; ++i)
            chk[a - h2 + 2 * i] = 1;
        queue<int> q;
        for (int i = 0; i <= n; ++i)
            if (chk[i]) q.push(i);
        cout << q.size() << '\n';
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }

    return 0;
}

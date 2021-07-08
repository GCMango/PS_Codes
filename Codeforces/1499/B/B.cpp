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
        string s; cin >> s;
        int zpos = -1, opos = -1;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '1') { opos = i; break; }
        for (int i = s.size() - 1; i >= 0; --i)
            if (s[i] == '0') { zpos = i; break; }
        bool ok = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool a = 1, b = 1;
            for (int j = 1; j < i; ++j)
                if (s[j] == '1' && s[j - 1] == '1') a = 0;
            for (int j = i + 1; j < s.size(); ++j)
                if (s[j] == '0' && s[j - 1] == '0') b = 0;
            ok |= (a && b);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}

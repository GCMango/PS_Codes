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

    int N, M; cin >> N >> M;
    string s; cin >> s;
    vector<string> v{"abc", "cab", "bca", "bac", "cba", "acb"};
    vector<vector<int>> arr(6, vector<int>(N));

    for (int i = 0; i < 6; ++i) {
        arr[i][0] = (s[0] != v[i][0]);
        for (int j = 1; j < N; ++j)
            arr[i][j] = arr[i][j - 1] + (s[j] != v[i][j % 3]);
    }

    while (M--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if (l == r) cout << "0\n";
        else if (r - l == 1) {
            if (s[l] == s[r]) cout << "1\n";
            else cout << "0\n";
        }
        else {
            int ans = 1e9;
            for (int i = 0; i < 6; ++i)
                ans = min(ans, arr[i][r] - (l ? arr[i][l - 1] : 0));
            cout << ans << '\n';
        }
    }

    return 0;
}

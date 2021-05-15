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

int dp[101][2][20], sum = 0;
string s, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == s[0])
            dp[i][0][0] = 1;
        if (b[i] == s[0])
            dp[i][1][0] = 1;
    }
    for (int i = 1; i < s.size(); ++i) {
        for (int j = i; j < a.size(); ++j) {
            for (int k = i - 1; k < j; ++k) {
                if (a[j] == s[i] && b[k] == s[i - 1])
                    dp[j][0][i] += dp[k][1][i - 1];
                if (b[j] == s[i] && a[k] == s[i - 1])
                    dp[j][1][i] += dp[k][0][i - 1];
            }
        }
    }

    for (int i = s.size() - 1; i < a.size(); ++i) {
        if (a[i] == s[s.size() - 1])
            sum += dp[i][0][s.size() - 1];
        if (b[i] == s[s.size() - 1])
            sum += dp[i][1][s.size() - 1];
    }

    cout << sum << '\n';

    return 0;
}

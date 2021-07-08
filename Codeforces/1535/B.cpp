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

bool gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a > 1);
}

void solve() {
    int N, cnt = 0;
    vector<int> a, b;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cnt += N - a.size() - 1;
            a.push_back(n);
        }
        else b.push_back(n);
    }
    for (int i = 0; i < b.size(); ++i)
        for (int j = i + 1; j < b.size(); ++j)
            cnt += gcd(b[i], b[j] * 2);
    cout << cnt << '\n';
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

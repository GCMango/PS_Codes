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

void solve() {
    int N, cnt = 0, sum = 0, m = 0;
    cin >> N;
    int n = N;
    while (N != 0) {
        N /= 10;
        cnt++;
    }
    sum += (cnt - 1) * 9;

    for (int i = 0; i < cnt; ++i)
        m += pow(10, i);
    cnt = 0;

    for (int i = 1; i <= 9; ++i) {
        if (m * i <= n) cnt++;
        else break;
    }
    
    cout << sum + cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

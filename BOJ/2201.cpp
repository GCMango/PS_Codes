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

    ll K, fibo[90]; cin >> K;
    string s; for (int i = 0; i < 90; ++i) s.push_back('0');
    fibo[0] = 0, fibo[1] = 1;
    for (int i = 2; i <= 90; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
    while (K) {
        auto pos = upper_bound(fibo, fibo + 90, K) - fibo;
        pos--;
        K -= fibo[pos];
        s[s.size() - pos + 1] = '1';
    }
    bool print = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') print = 1;
        if (print) cout << s[i];
    }
    cout << '\n';

    return 0;
}

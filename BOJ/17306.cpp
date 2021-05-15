#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define log(x) 64 - __builtin_clzll(x)
#define par(x, i) (long long)(x / pow(2, i))
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll n, m, sum = 0;
    const int MAX_LVL = (int)floor(log2(250000));
    cin >> N;

    cin >> n;
    for (int i = 1; i < N; ++i) {
        cin >> m;
        ll mm = m;
        if (log(n) != log(m)) {
            if (log(n) >= log(m))
                swap(n, m);
            for (int i = MAX_LVL; i > 0; --i)
                if (log(n) <= log(par(m, i)))
                    m = par(m, i);
        }
        ll lca = n;
        if (n != m) {
            for (int i = MAX_LVL; i > 0; --i) {
                if (log(par(n, i)) != log(par(m, i)) && par(n, i) != 0) {
                    n = par(n, i);
                    m = par(m, i);
                }
                lca = par(n, i);
            }
        }
        int logn = log(n), logl = log(lca), logm = log(mm);
        sum += logn - logl + logm - logl;
        if (logn == logl || logm == logl) sum++;
        n = lca;
    }

    cout << sum << "\n";

    return 0;
}

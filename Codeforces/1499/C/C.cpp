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
        int N; cin >> N;
        int suma[100000], sumb[100000], mna = 1e9, mnb = 1e9;
        vector<int> a, b;
        for (int i = 0; i < N; ++i) {
            int n; cin >> n;
            if (i % 2) b.push_back(n);
            else a.push_back(n);
        }
        suma[0] = a[0] * N, sumb[0] = b[0] * N;
        int mna = a[0], mnb = b[0];
        for (int i = 0; i < a.size(); ++i) {
            if (mna > a[i]) {

            }
        }
    }

    return 0;
}

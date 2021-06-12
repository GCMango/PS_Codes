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

int N, a[500005], b[500005];
ll ans = 0;

void dfs(int s, int e) {
    if (s == e) return;

    int m = (s + e) / 2;
    dfs(s, m); dfs(m + 1, e);

    int i = s, j = m + 1, idx = s, cnt = 0;
    while (i <= m || j <= e) {
        if (i > m) {
            b[idx++] = a[j++]; cnt++;
        } else if (j > e) {
            b[idx++] = a[i++]; ans += (ll)cnt;
        } else if (a[i] <= a[j]) {
            b[idx++] = a[i++]; ans += (ll)cnt;
        } else {
            b[idx++] = a[j++]; cnt++;
        }
    }

    for (i = s; i <= e; ++i) a[i] = b[i];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> a[i];
    dfs(1, N);
	cout << ans << '\n';
    
    return 0;
}

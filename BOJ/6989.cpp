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
    
const int MXN = 152, MXM = 1140000;
int N, K, arr[MXN], sum[MXN][MXN];
bitset<MXM> bit[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i], arr[i] += arr[i - 1];
    cin >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; ++j)
            sum[i][j] = sum[i][j - 1] + arr[j] - arr[i - 1];
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i + 1; ++j) {
            if (j <= 2)
                bit[i].set(sum[j][i]);
            else
                bit[i] |= (bit[j - 2] << sum[j][i]);
        }
    }
    int ans = K;
    while (ans <= sum[1][N] && bit[N].test(ans)) ans++;
    cout << ans << '\n';

    return 0;
}

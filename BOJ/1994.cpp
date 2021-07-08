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

int N, cnt, max_cnt, ans, arr[2000], dp[2000][2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i - 1]) cnt++;
        else { max_cnt = max(max_cnt, cnt + 1); cnt = 0; }
    }
    max_cnt = max(max_cnt, cnt + 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            int comp = arr[i] - arr[j];
            int pos = lower_bound(arr, arr + N, arr[j] - comp) - arr;
            if (arr[pos] == arr[j] - comp) dp[i][j] = max(2, dp[j][pos] + 1);
            else dp[i][j] = 2;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << max(max_cnt, ans) << '\n';

    return 0;
}

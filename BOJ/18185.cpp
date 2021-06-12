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

    int N, arr[10000];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int sum = 1, ans = 0;
    while (sum != 0) {
        sum = 0;
        for (int i = 0; i < N; ++i) {
            if (i < N - 2 && arr[i] && arr[i + 1] && arr[i + 2]) {
                arr[i]--; arr[i + 1]--; arr[i + 2]--;
                ans += 7;
            }
            else if (i < N - 1 && arr[i] && arr[i + 1]) {
                arr[i]--; arr[i + 1]--;
                ans += 5;
            }
            else if (arr[i]) {
                arr[i]--;
                ans += 3;
            }
            sum += arr[i];
        }
    }
    cout << ans << '\n';

    return 0;
}

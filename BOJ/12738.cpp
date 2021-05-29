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

int N, len = 0, input[1000001], l[1000001], p[1000001];

void traceback(int cur, int num) {
    if (cur == 0) return;
    if (p[cur] == num) {
        traceback(cur - 1, num - 1);
        cout << input[cur] << ' ';
    }
    else
        traceback(cur - 1, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> input[i];
        auto pos = lower_bound(l + 1, l + len + 1, input[i]);
        *pos = input[i];
        p[i] = distance(l, pos);
        if (pos == l + len + 1)
            len++;
    }
    cout << len << '\n';
    traceback(N, len);
    cout << '\n';

    return 0;
}


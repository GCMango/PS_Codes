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
    
int N, len = 0, p[100001], l[100001];
pii input[100001];
bool check[100001];
vector<int> ans;

void backtrace(int cur, int num) {
    if (cur == 0) return;
    if (p[cur] == num) {
        backtrace(cur - 1, num - 1);
        check[cur] = true;
    }
    else
        backtrace(cur - 1, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> input[i].x >> input[i].y;
    sort(input + 1, input + N + 1, [&](pii &a, pii &b) {
        return a.x < b.x;
    });

    for (int i = 1; i <= N; ++i) {
        auto pos = lower_bound(l + 1, l + len + 1, input[i].y);
        *pos = input[i].y;
        p[i] = distance(l, pos);
        if (pos == l + len + 1)
            len++;
    }

    cout << N - len << '\n';
    backtrace(N, len);

    for (int i = 1; i <= N; ++i)
        if (!check[i])
            cout << input[i].x << '\n';

    return 0;
}

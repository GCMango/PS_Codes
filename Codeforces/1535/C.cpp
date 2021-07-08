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

int tree[100], N, M;
vector<int> v;

int seg(int s, int e, int cur) {
    if (s == e) return tree[cur] = (v[cur] <= 1) ? 1 : 2;
    int m = (s + e) / 2;
    int a = seg(s, m, cur * 2), b = seg(m + 1, e, cur * 2 + 1);
    if (v[cur] == 2) tree[cur] = a + b;
    else tree[cur] = (v[s] == 0) ? b : a;
    return tree[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    string s;
    cin >> s;
    int cnt = 1, a = s.size();
    N = a;
    v.clear(); v.push_back(-1);
    memset(tree, 0, sizeof(tree));
    while (a - cnt >= 0) {
        for (int i = a - 1; i >= a - cnt; --i) {
            if (s[i] == '0' || s[i] == '1')
                v.push_back(s[i] - '0');
            else v.push_back(2);
        }
        a -= cnt;
        cnt *= 2;
    }
    cin >> M;
    while (M--) {
        int idx; char c;
        cin >> idx >> c;
        idx = N - idx + 1;
        if (c == '?') v[idx] = 2;
        else v[idx] = c - '0';
        cout << seg(1, N, 1) << '\n';
    }

    return 0;
}

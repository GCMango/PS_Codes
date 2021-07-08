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

int tree[300000], N, M;
vector<int> v{-1};

int init(int s, int e, int cur) {
    if (s == e) return tree[cur] = (v[cur] <= 1) ? 1 : 2;
    int m = (s + e) / 2;
    int a = init(s, m, cur * 2), b = init(m + 1, e, cur * 2 + 1);
    if (v[cur] == 2) tree[cur] = a + b;
    else tree[cur] = (v[cur] == 0) ? b : a;
    return tree[cur];
}

int update(int s, int e, int cur, int pos, int div) {
    if (s == e) return tree[cur] = (v[cur] <= 1) ? 1 : 2;
    int m = (s + e) / 2;
    int a = tree[cur * 2], b = tree[cur * 2 + 1];
    if (!div) div = pos + 1;
    int ch = pos / div;
    if (ch == cur * 2) a = update(s, m, cur * 2, pos, div / 2);
    else b = update(m + 1, e, cur * 2 + 1, pos, div / 2);
    if (v[cur] == 2) tree[cur] = a + b;
    else tree[cur] = (v[cur] == 0) ? b : a;
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
    N = a; K--;
    while (a - cnt >= 0) {
        for (int i = a - 1; i >= a - cnt; --i) {
            if (s[i] == '0' || s[i] == '1')
                v.push_back(s[i] - '0');
            else v.push_back(2);
            //cout << v.back();
        }
        a -= cnt; cnt *= 2;
        //cout << '|';
    }
    //cout << '\n';

    init(1, (1 << K), 1);

    cin >> M;
    while (M--) {
        int idx, r, pos; char c;
        cin >> idx >> c;
        idx = N - idx + 1;
        v[idx] = (c == '?') ? 2 : c - '0';
        cout << update(1, (1 << K), 1, idx, 1 << (30 - __builtin_clz(idx))) << '\n';
        /*cnt = a = 1;
        for (int i = 1; i <= N; ++i) {
            cout << v[i];
            a++;
            if (a > cnt) {
                cout << '|';
                a = 1;
                cnt *= 2;
            }
        }
        cout << '\n';
        cnt = a = 1;
        for (int i = 1; i <= N; ++i) {
            cout << tree[i];
            a++;
            if (a > cnt) {
                cout << '|';
                a = 1;
                cnt *= 2;
            }
        }
        cout << '\n';*/
    }

    return 0;
}



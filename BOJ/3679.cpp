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

struct INFO {
    ll x, y;
    ll p, q;
    ll n;
    INFO (ll xx = 0, ll yy = 0, ll nn = 0) : x(xx), y(yy), p(1), q(0), n(nn) {}
};

bool comp(INFO &a, INFO &b) {
    if (a.q * b.p != a.p * b.q)
        return a.q * b.p < a.p * b.q;
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

ll ccw(INFO &a, INFO &b, INFO &c) {
    ll first = (b.x - a.x) * (c.y - a.y);
    ll second = (b.y - a.y) * (c.x - a.x);
    return first - second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<INFO> arr(N);
        
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            arr[i] = INFO(x, y, i);
        }
    
        sort(all(arr), comp);
    
        for (int i = 1; i < N; ++i)
            arr[i].p = arr[i].x - arr[0].x, arr[i].q = arr[i].y - arr[0].y;
    
        sort(all(arr), comp);

        for (int i = 2; i < N; ++i) {
            INFO &a = arr[i - 2], &b = arr[i - 1];
            INFO &c = arr[i];
            if (ccw(a, b, c) == 0) {
                ll db = abs(b.x - a.x) + abs(b.y - a.y);
                ll dc = abs(c.x - a.x) + abs(c.y - a.y);
                if (dc < db) swap(b, c);
            }
        }

        for (int i = 0; i < N; ++i)
            cout << arr[i].n << ' ';
        cout << '\n';
    }

    return 0;
}



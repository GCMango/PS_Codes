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
    INFO (ll xx = 0, ll yy = 0) : x(xx), y(yy), p(1), q(0) {}
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

    int N;
    cin >> N;
    vector<INFO> arr(N);
    
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        arr[i] = INFO(x, y);
    }

    sort(all(arr), comp);

    for (int i = 1; i < N; ++i)
        arr[i].p = arr[i].x - arr[0].x, arr[i].q = arr[i].y - arr[0].y;

    sort(all(arr), comp);

    stack<int> st;
    st.push(0);
    st.push(1);
    int next = 2;
    while (next < N) {
        while (st.size() >= 2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();

            if (ccw(arr[first], arr[second], arr[next]) > 0) {
                st.push(second);
                break;
            }
        }
        st.push(next++);
    }

    cout << st.size() << '\n';

    return 0;
}


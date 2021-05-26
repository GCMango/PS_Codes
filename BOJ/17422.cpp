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

int N, Q;
ll input[300003], A[300003], B[300003];
priority_queue<ll> pq, cpq;

void solve(int cur) {
    ll l = 0, r = 0;
    if (cur * 2 <= N) {
        solve(cur * 2);
        l = A[cur * 2];
    }
    if (cur * 2 + 1 <= N) {
        solve(cur * 2 + 1);
        r = A[cur * 2 + 1];
    }
    B[cur] = input[cur] + l + r;
    pq.push(B[cur]);
    A[cur] = input[cur] + max(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> input[i];

    solve(1);

    cout << pq.top() << '\n';
    
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        input[a] = b;
        while (a) {
            ll l = (a * 2 > N ? 0 : A[a * 2]), r = (a * 2 + 1 > N ? 0 : A[a * 2 + 1]);
            cpq.push(B[a]);
            B[a] = input[a] + l + r;
            A[a] = input[a] + max(l, r);
            pq.push(B[a]);
            a /= 2;
        }
        while (!pq.empty() && !cpq.empty() && pq.top() == cpq.top()) {
            pq.pop();
            cpq.pop();
        }
        cout << pq.top() << '\n';
    }

    return 0;
}

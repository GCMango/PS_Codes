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

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        int n; cin >> n;
        pq.push(n);
    }
    int sum = 0;
    while (!pq.empty()) {
        int a = pq.top(), b; pq.pop();
        if (pq.empty()) break;
        b = pq.top(); pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << sum << '\n';

    return 0;
}

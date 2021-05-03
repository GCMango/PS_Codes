#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll mod = 1e9 + 7;

int N;
ll sum = 0;
vector<vector<p>> node;

ll solve(int cur, int pnode) {
	ll mult = 1;
	for (int i = 0; i < node[cur].size(); ++i) {
		int child = node[cur][i].x;
		int dist = node[cur][i].y;
		if (child == pnode) continue;

        ll solution = (dist * solve(child, cur)) % mod;
        sum += mult * solution; sum %= mod;
        mult += solution; mult %= mod;
	}

	return mult;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	node.resize(N + 1);

	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({b, c});
		node[b].push_back({a, c});
	}

	solve(1, 0);
	cout << sum << "\n";
	
	return 0;
}


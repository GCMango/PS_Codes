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

const int MXN = 500005;

struct Test {
    int a;
    int b;
    int c;
};

int N, tree[MXN * 4];
Test arr[MXN];

int seg(int s, int e, int cur) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i].a;
    for (int i = 1; i <= N; ++i) cin >> arr[i].b;
    for (int i = 1; i <= N; ++i) cin >> arr[i].c;
    cout << seg(1, N, 1) << '\n';

    return 0;
}
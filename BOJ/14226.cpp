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

struct Emoji {
    int len;
    int clip;
    int cnt;
};

int N, ans;
bool visited[5000][5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    queue<Emoji> que;
    que.push({1, 0, 0});
    while (!que.empty()) {
        Emoji cur = que.front();
        que.pop();
        int len = cur.len, clip = cur.clip, cnt = cur.cnt;
        if (visited[len][clip]) continue;
        visited[len][clip] = true;
        if (len == N) {
            ans = cnt;
            break;
        }
        cnt++;
        if (clip > 0)
            que.push({len + clip, clip, cnt});
        if (len > 1)
            que.push({len - 1, clip, cnt});
        que.push({len, len, cnt});
    }
    cout << ans << '\n';

    return 0;
}

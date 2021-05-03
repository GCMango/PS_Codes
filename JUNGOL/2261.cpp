#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, vector<int>> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, A, B;
    cin >> N >> K;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    cin >> A >> B;
    A--; B--;

    queue<p> que;
    que.push({A, vector<int>{A}});
    vector<int> result(1000);
    vector<int> visited(N, 0);

    while (!que.empty()) {
        p cur = que.front();
        que.pop();
        if (cur.x == B) {
            if (cur.y.size() < result.size())
                result = cur.y;
            continue;
        }
        if (visited[cur.x] || cur.y.size() >= result.size()) continue;
        visited[cur.x] = 1;
        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;
            int cnt = 0;
            for (int j = 0; j < K; ++j)
                if (arr[cur.x][j] != arr[i][j]) cnt++;
            if (cnt == 1) {
                cur.y.push_back(i);
                que.push({i, cur.y});
                cur.y.pop_back();
            }
        }
    }

    if (result.size() == 1000) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < result.size(); ++i) cout << result[i] + 1 << ' ';
    cout << "\n";

    return 0;
}

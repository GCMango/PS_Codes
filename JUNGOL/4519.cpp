#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, vector<int>> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    const vector<int> option{60, 10, -10, 1, -1};
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr{0, 0, 0, 0, 0};
        arr[0] += N / 60;
        N %= 60;
        queue<p> que;
        que.push({0, arr});
        while (!que.empty()) {
            p cur = que.front();
            que.pop();
            if (cur.x == N) {
                arr = cur.y;
                break;
            }
            for (int i = option.size() - 1; i >= 0; --i) {
                if (cur.x == 0 && option[i] < 0) continue;
                cur.y[i]++;
                int num = (cur.x + option[i] < 0 ? 0 : cur.x + option[i]);
                que.push({num, cur.y});
                cur.y[i]--;
            }
        }
        for (int i = 0; i < arr.size(); ++i) cout << arr[i] << ' ';
        cout << "\n";
    }

    return 0;
}

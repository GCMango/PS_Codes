#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        string comp = s;
        int cnt = 0;
        do {
            int sum = 0;
            for (int i = 0; i < s.size(); ++i)
                sum += (s[i] - '0') * (s[i] - '0');
            s = to_string(sum);
            cnt++;
        } while(cnt < 10 && s != "1");
        if (s == "1") cout << "GREAT\n";
        else cout << "STUPID\n";
    }

    return 0;
}

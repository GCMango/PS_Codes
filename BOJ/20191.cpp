#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        bool exist = false;
        for (int j = 0; j < b.size(); ++j)
            if (a[i] == b[j])
                exist = true;
        if (!exist) {
            cout << "-1\n";
            return 0;
        }
    }

    int i = 0, j = 0, cnt = 1;
    string c = b;
    while (1) {
        if (a[i] == b[j])
            i++;
        j++;
        if (j >= b.size()){
            j = 0;
            cnt++;
        }
        if (i >= a.size()) break;
    }

    cout << cnt << "\n";

    return 0;
}


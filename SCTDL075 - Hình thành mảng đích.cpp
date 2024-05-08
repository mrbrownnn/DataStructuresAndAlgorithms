#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        int res = a[0];
        for (int i = 1; i < n; i ++) {
            res += max(0, a[i] - a[i - 1]);
        }
        cout << res << endl;
    }
    return 0;
}
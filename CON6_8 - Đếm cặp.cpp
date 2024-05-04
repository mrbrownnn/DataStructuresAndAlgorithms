
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairs(vector<int>& X, vector<int>& Y) {
    int count = 0;
    int n = X.size();
    int m = Y.size();

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 0; i < n; i++) {
        if (X[i] == 0)
            continue;

        if (X[i] == 1) {
            count += 0;
        } else {
            int idx = upper_bound(Y.begin(), Y.end(), X[i]) - Y.begin();
            count += m - idx;
            if (X[i] == 2)
                count--;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> X(n);
        vector<int> Y(m);

        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> Y[i];
        }

        int result = countPairs(X, Y);
        cout << result << endl;
    }

    return 0;
}